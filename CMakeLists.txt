cmake_minimum_required(VERSION 3.31)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake_game
        src/glad.c
        src/main.cpp
)

find_package(OpenGL REQUIRED)

target_include_directories(snake_game PRIVATE
        include
)

target_link_libraries(snake_game PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw3dll.a
        OpenGL::GL
)

# Copy glfw3.dll to the output directory
add_custom_command(TARGET snake_game
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/glfw3.dll"
        "$<TARGET_FILE_DIR:snake_game>/glfw3.dll"
        COMMENT "Copying glfw3.dll to output directory"
)