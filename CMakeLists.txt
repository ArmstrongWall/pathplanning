# 作者  ： JohnnyWang
# log   :   
#=======2017.10.21.16:35(星期六)======= 创建文件

cmake_minimum_required(VERSION 2.8)
#工程名
PROJECT (pathplanning)
#设置全局变量
#set (EXTRA_LIBS ${EXTRA_LIBS} state context)
#注意，如果一个库要引用其他库的函数，需要将被引用的库放在后面
find_package (OpenGL REQUIRED)
#添加库文件
#add_library(state     SHARED src/state.cpp)
#add_library(context   SHARED src/context.cpp)
#添加可执行文件
add_executable(pathplanning src/main.cc)
#链接
target_link_libraries(pathplanning GL GLU glut)
