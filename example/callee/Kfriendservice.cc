#include <iostream>
#include <string>
#include "friend.pb.h"
#include "Krpcapplication.h"
#include "Krpcprovider.h"

class FiendService : public Kfriend::FiendServiceRpc // 继承自 protobuf 生成的 RPC 服务基类
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout << "do GetFriendsList service! userid:" << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        vec.push_back("wang shuo");
        return vec;
    }

    void GetFriendsList(::google::protobuf::RpcController* controller,
        const ::Kfriend::GetFriendsListRequest* request,
        ::Kfriend::GetFriendsListResponse* response,
        ::google::protobuf::Closure* done) 
    {
        uint32_t userid = request->userid();
        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char **argv) {
    // 调用框架的初始化操作，解析命令行参数并加载配置文件
    KrpcApplication::Init(argc, argv);

    // 创建一个 RPC 服务提供者对象
    KrpcProvider provider;

    // 将 FriendService 对象发布到 RPC 节点上，使其可以被远程调用
    provider.NotifyService(new FiendService());

    // 启动 RPC 服务节点，进入阻塞状态，等待远程的 RPC 调用请求
    provider.Run();

    return 0;
}