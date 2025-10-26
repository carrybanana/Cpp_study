# 最低 CMake 版本, 模块支持需要较新版本
cmake_minimum_required(VERSION 4.0.2)

# 1. 设置 STD Module 的实验性 UUID
# 查询实验性 UUID 需前往 CMake 的 Github仓库 或 Gitlab仓库 ，在项目的 Help/dev/experimental.rst 文件中，可以找到 C++ import std support 栏目，提供了相关内容。
# 需要注意的是，此 UUID 与 CMake 版本挂钩，你不能直接复制 master/main 分支下的 UUID，而应该使用和你版本匹配的 Tag 下的 UUID 。你可以在本地通过 cmake --version 命令查看本地CMake版本。
# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")   # cmake version 4.1.2

# 2. 项目名称和语言
project(Employee_struct_project LANGUAGES CXX)

# 3. 基础配置：C++26 标准 + 导出 compile_commands.json
set(CMAKE_CXX_MODULE_STD on)
set(CMAKE_CXX_STANDARD 26)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)       # 导出编译数据库，让 clangd 识别模块

# 4. 添加 employee 子模块（会执行 employee/CMakeLists.txt）
add_subdirectory(employee)

# 5. 生成主程序可执行文件
add_executable(main
    main.cpp                                # 添加可执行文件
)

# 6. 链接 employee 模块库（关键！让主程序找到 employee 模块）
target_link_libraries(main PRIVATE employee)

# 或使用目标参数
# set_target_properties(main PROPERTIES
#     CXX_MODULE_STD on
#     CXX_STANDARD 23
# )
