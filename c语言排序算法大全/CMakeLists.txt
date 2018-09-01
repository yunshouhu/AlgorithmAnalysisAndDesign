# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (all_sort)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(. DIR_SRCS)

file(GLOB main_src all_sort.c)
SET( main_src ${main_src})  

# 添加 math 子目录
#add_subdirectory(math)

# 指定生成目标
add_executable(all_sort ${main_src} )

# 添加链接库
#target_link_libraries(Demo MathFunctions)

# 指定生成 Linking C static library libJMEncryptBox.a 链接库
#add_library (JMEncryptBox ${DIR_SRCS})  #static
#add_library (JMEncryptBox_x64 SHARED ${DIR_SRCS})
#add_library (JMEncryptBox_x64 STATIC ${DIR_SRCS})
