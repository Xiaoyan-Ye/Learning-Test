cmake_minimum_required(VERSION 3.4.1)
project(SDL_test)

SET(CMAKE_C_COMPILER mingw32-gcc)
SET(CMAKE_CXX_COMPILER mingw32-g++)
#include_directories(C:/Users/mwang9/Downloads/Tool/SDL2-2.0.10/i686-w64-mingw32/include/SDL2)
#link_directories(C:/Users/mwang9/Downloads/Tool/SDL2-2.0.10/i686-w64-mingw32/lib)
SET(EXECUTABLE_OUTPUT_PATH ../lib)  


add_executable(SDL_test sdl_test.cpp)
target_link_libraries(SDL_test mingw32 SDL2main SDL2)