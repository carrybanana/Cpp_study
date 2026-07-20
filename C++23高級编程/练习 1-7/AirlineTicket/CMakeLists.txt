cmake_minimum_required(VERSION 4.0.2)       # 模块支持需要较新版本

# 1. 定义 AirlineTicket 模块库（静态库，类型不重要，关键是封装模块）
add_library(AirlineTicket STATIC)

# 2. 给 AirlineTicket 库添加模块文件（接口 + 实现）
# 注：GCC 15/Clang 要求模块接口文件用 .cppm 后缀（.ixx 也支持，.cppm 更通用）
target_sources(AirlineTicket
    PRIVATE
        AirlineTicket.cpp                        # 模块实现（内部逻辑，不对外暴露）
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES     # 声明这是 C++ 模块文件
        AirlineTicket.cppm                   # 模块接口（对外暴露的类/函数）
)
