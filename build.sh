#!/bin/bash
###
 # @Description: 
 # @Version: 
 # @Autor: guanzhou
 # @email: guanzhou.cn@gmail.com
 # @Date: 2022-04-08 21:08:53
 # @LastEditors: guanzhou
 # @LastEditTime: 2022-04-08 21:37:31
### 

set -e

# for rk1808 aarch64
GCC_COMPILER=/home/tuto/code/1808/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu

# for rk1806 armhf
# GCC_COMPILER=~/opts/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf

# for rv1109/rv1126 armhf
# GCC_COMPILER=~/opts/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf

ROOT_PWD=$( cd "$( dirname $0 )" && cd -P "$( dirname "$SOURCE" )" && pwd )

# build rockx
BUILD_DIR=${ROOT_PWD}/build


cmake ./ \
    -DCMAKE_C_COMPILER=${GCC_COMPILER}-gcc \
    -DCMAKE_CXX_COMPILER=${GCC_COMPILER}-g++
make -j4

