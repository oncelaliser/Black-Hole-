cmake_minimum_required (VERSION 3.8)

project(TON618 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENGL_LIBS_DIR
"C:/Users/kükreyen ejderha/source/repos/YouTubeOpenGL/Libraries"
)
set(GLFW_INCLUDE_DIR "${OPENGL_LIBS_DIR}/include")
set(GLFW_LIBRARY "${OPENGL_LIBS_DIR}/lib/glfw3.lib")
set(GLAD_SOURCE
"C:/Users/kükreyen ejderha/source/repos/YouTubeOpenGL/glad.c"
)

add_executable(TON618
TON618.cpp
TON618.h
"${GLAD_SOURCE}"
)
#Header search paths
target_include_directories(TON618 PRIVATE
"${GLFW_INCLUDE_DIR}"
)
#Link GLFW and Windows system libraries
target_link_libraries(TON618 PRIVATE
"${GLFW_LIBRARY}"
opengl32
)