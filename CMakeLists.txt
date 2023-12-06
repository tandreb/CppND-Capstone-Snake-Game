cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

# Specify SDL_ttf include and link directories
set(SDL_TTF_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL_TTF_LIBRARIES "-lSDL2_ttf")

include_directories(${SDL_TTF_INCLUDE_DIRS})

add_executable(SnakeGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/snake.cpp)

# Link SDL2 libraries
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

# Link SDL_ttf libraries
target_link_libraries(SnakeGame ${SDL_TTF_LIBRARIES})
