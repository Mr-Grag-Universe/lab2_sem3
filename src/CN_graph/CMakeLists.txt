cmake_minimum_required(VERSION 3.16)
project(CN_graph_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(CN_graph_lib
        CN_graph.cpp
        CN_graph.h
        application.qrc
        )


set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\")
find_package(Qt5Widgets REQUIRED)

target_link_libraries(CN_graph_lib Qt5::Widgets)