cmake_minimum_required(VERSION 3.22)
project(glfw-starter)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(glfw-starter src/main.cpp src/graphics/Window.cpp src/graphics/Window.h src/math/shapes/Arc.cpp src/math/shapes/Arc.h src/math/vector/Vector3D.cpp src/math/vector/Vector3D.h src/math/point/Point3D.cpp src/math/point/Point3D.h src/gui/MyWindow.cpp src/gui/MyWindow.h src/math/point/Point2D.cpp src/math/point/Point2D.h src/math/vector/Vector2D.cpp src/math/vector/Vector2D.h)

add_subdirectory(libs/glfw)
target_link_libraries(glfw-starter glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(glfw-starter OpenGL::GL)
