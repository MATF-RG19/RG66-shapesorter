cmake_minimum_required(VERSION 3.5)

project(ShapeSorter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

add_executable(shapeSorter 
    src/main.cpp 
    src/figures.cpp
    src/display.cpp
    src/utils.cpp
    src/keyboard.cpp
    src/timers.cpp
)
    


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(shapeSorter ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
