cmake_minimum_required(VERSION 3.22)
project(glfw-starter)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.)

add_executable(
        glfw-starter
        app/main.cpp
        src/graphics/Window.cpp
        src/graphics/Window.h
        src/math/shapes/Arc.cpp
        src/math/shapes/Arc.h
        src/math/vector/Vector3D.cpp
        src/math/vector/Vector3D.h
        src/math/point/Point3D.cpp
        src/math/point/Point3D.h
        app/gui/MyWindow.cpp
        app/gui/MyWindow.h
        src/math/point/Point2D.cpp
        src/math/point/Point2D.h
        src/math/vector/Vector2D.cpp
        src/math/vector/Vector2D.h
        src/math/spline/Spline.cpp
        src/math/spline/Spline.h
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        shaders/vertex/vertex.frag.glsl
        shaders/vertex/vertex.vert.glsl
)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

find_package(OpenGL REQUIRED)

target_link_libraries(glfw-starter glfw)
target_link_libraries(glfw-starter OpenGL::GL)
target_link_libraries(glfw-starter glm)
