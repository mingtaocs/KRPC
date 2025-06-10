#设置最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(Krpc)

#设置全局的C++标准
set(CMAKE_CXX_STANDARD 11)#使用c++11标准
set(CMAKE_CXX_STANDARD_REQUIRED True)#CMAKE_CXX_STANDARD_REQUIRED表示强制使用指定的标准

set(PROTO_GEN_DIR ${PROJECT_SOURCE_DIR}/example/generated)
file(MAKE_DIRECTORY ${PROTO_GEN_DIR})
include_directories(${PROTO_GEN_DIR})

#查找porotbuf库
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})#Protobuf_INCLUDE_DIRS表示protobuf头文件目录

#设置头文件目录，供所有子项目使用
#include_directories(${​​PROJECT_SOURCE_DIR}/src/include) 


# 生成debug版本，可以进行gdb调试
set(CMAKE_BUILD_TYPE "Debug")

# 设置项目可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


#设置全局链接库
set(LIBS
    protobuf
    pthread
    zookeeper_mt
    muduo_net
    muduo_base
    glog
)
#添加子目录
add_subdirectory(src)
add_subdirectory(example)
