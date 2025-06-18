# Snake Game

A simple Snake game implemented in C/C++ using OpenGL and GLFW.

## Features

- Classic Snake gameplay
- OpenGL rendering
- Cross-platform codebase

## Requirements

- CMake 3.10 or higher
- C/C++ compiler (e.g., MSVC, MinGW, or Clang)
- [GLFW](https://www.glfw.org/) library
- OpenGL

## Build Instructions (Windows)

1. **Clone the repository:**
   ```
    git clone https://github.com/rahulc0dy/snake-game.git
    cd snake-game
   ```

2. **Install dependencies:**
   - Download and build GLFW, or use pre-built binaries.
   - Make sure `glfw3.lib` and `glfw3.dll` are available.

3. **Configure and build the project:**
   ```
    cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
    cmake --build cmake-build-debug
   ```

4. **Copy required DLLs:**
   - Copy `glfw3.dll` to the `cmake-build-debug` directory (next to `snake_game.exe`).

5. **Run the game:**
   ```
    cd cmake-build-debug
    snake_game.exe
   ```

## Troubleshooting

- If you see an error about a missing DLL (`0xC0000135`), ensure `glfw3.dll` is in the same directory as the executable or in your system `PATH`.
- Make sure your graphics drivers support OpenGL.

## License

This project is licensed under the MIT License.