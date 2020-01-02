cmake_minimum_required(VERSION 3.5)

project(ShapeSorter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp figures.cpp figures.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
