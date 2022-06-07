cmake_minimum_required(VERSION 3.22)
project(glfw-starter)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(glfw-starter src/main.cpp src/window/Window.cpp src/window/Window.h)

add_subdirectory(libs/glfw)
target_link_libraries(glfw-starter glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(glfw-starter OpenGL::GL)
