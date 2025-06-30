cmake_minimum_required(VERSION 3.31)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME}
        src/glad.c
        src/main.cpp
)

find_package(OpenGL REQUIRED)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        include
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw3dll.a
        OpenGL::GL
)

# Copy glfw3.dll to the output directory
add_custom_command(TARGET ${CMAKE_PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/glfw3.dll"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/glfw3.dll"
        COMMENT "Copying glfw3.dll to output directory"
)