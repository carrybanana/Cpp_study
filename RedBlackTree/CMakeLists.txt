# 指定最低支持的 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(RedBlackTreeProject LANGUAGES CXX)

# 指定使用 C++17
set(CMAKE_CXX_STANDARD 17)
# 要求必须支持 C++17，否则报错
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件，包含源文件
add_executable(rbtree_test
    testing.cpp
)
