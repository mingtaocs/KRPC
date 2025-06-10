#pragma once

#include<glog/logging.h>
#include<string>
//采用RAII的思想
class KrpcLogger
{
public:
      //构造函数，自动初始化glog
      explicit KrpcLogger(const char *argv0)
    {
        google::InitGoogleLogging(argv0);
        FLAGS_colorlogtostderr = true;  // 启用彩色日志（控制台）
        FLAGS_logtostderr = false;       // 禁用默认输出到stderr
        FLAGS_log_dir = "../logs";      // 日志保存到./logs目录
        
       FLAGS_minloglevel = 0; //设置日志级别，INFO	0	普通信息（默认级别）WARNING	1	警告信息，表明潜在问题 ERROR	2	错误信息，需要关注但程序可能继续运行 FATAL	3	致命错误，程序会终止并生成核心转储文件
    }
      ~KrpcLogger(){
        google::ShutdownGoogleLogging();
      }
      //提供静态日志方法
      static void Info(const std::string &message)
      {
        LOG(INFO)<<message;
      }
      static void Warning(const std::string &message){
        LOG(WARNING)<<message;
      }
      static void ERROR(const std::string &message){
        LOG(ERROR)<<message;
      }
          static void Fatal(const std::string& message) {
        LOG(FATAL) << message;
    }
//禁用拷贝构造函数和重载赋值函数
private:
    KrpcLogger(const KrpcLogger&)=delete;
    KrpcLogger& operator=(const KrpcLogger&)=delete;
};

