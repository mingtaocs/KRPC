#!/bin/bash
set -eo pipefail

INSTALL_DIR="output"  # 安装目录
NPROC=$(nproc)       # 获取CPU核心数

# 1. 创建并进入构建目录
mkdir -p build && cd build

# 2. 配置项目（生成Makefile）
cmake .. \
    -DCMAKE_INSTALL_PREFIX="../${INSTALL_DIR}" \
    -DCMAKE_BUILD_TYPE=Release

# 3. 编译并安装
make -j"${NPROC}"
