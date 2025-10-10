# ========================== 基础配置 ==========================
cmake_minimum_required(VERSION 4.1.0)        # 模块支持需要较新版本
project(test_project LANGUAGES CXX)         # 项目名称

# ========================== 强制使用 GCC（可选）==========================
# 如果你系统有多个编译器（如 clang 和 gcc），可显式指定
if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "该项目要求使用 GCC 编译器，当前使用的是 ${CMAKE_CXX_COMPILER_ID}")
endif()

# ========================== C++标准设置 ==========================
set(CMAKE_CXX_STANDARD 26)                  # 启用C++26标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)         # 强制要求C++26，不降级
set(CMAKE_CXX_EXTENSIONS OFF)               # 禁用编译器扩展（保证标准兼容性）

# 可选：启用模块支持（但标准库仍需 #include）
# 注意：GCC 的模块支持仍实验性，需手动处理 .cppm 文件等
# set(CMAKE_CXX_SCAN_FOR_MODULES ON)  # CMake 3.28+ 支持

# ========================== 定义可执行目标 ==========================
# 1. 添加可执行文件
add_executable(main
    main.cpp        # 主程序代码
)
