
set(CMAKE_CXX_STANDARD 23)

# Find source files
file(GLOB_RECURSE SRCS "*.cpp" "*.c")
add_executable("app" ${SRCS})

target_link_libraries(app PRIVATE glm)
target_link_libraries(app PRIVATE glfw)
target_link_libraries(app PRIVATE OpenGL)
target_include_directories(app PRIVATE .)
