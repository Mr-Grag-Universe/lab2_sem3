cmake_minimum_required(VERSION 3.16)
# project(lab1_sem3)

set(CMAKE_CXX_STANDARD 17)

include_directories(CN_graph)
add_subdirectory(CN_graph)
# add_executable(lab1_sem3 main.cpp compressed_matrix_lib/CSR.cpp compressed_matrix_lib/ListMatrix.cpp compressed_matrix_lib/input.cpp compressed_matrix_lib/matrixes.h compressed_matrix_lib/input.h)

# Установите BINARY в имя проекта IndexProject
set(BINARY ${CMAKE_PROJECT_NAME})

# 1
add_executable(lab2_sem3 main.cpp interaction.cpp)
target_link_libraries(lab2_sem3 CN_graph_lib)

# 2
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY}_run ${SOURCES})
# Чтобы код из src можно было использовать в качестве библиотеки статических ссылок во время модульного тестирования
add_library(${BINARY}_lib STATIC ${SOURCES})