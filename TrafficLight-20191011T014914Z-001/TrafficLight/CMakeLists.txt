cmake_minimum_required(VERSION 3.4.1)
project(trafficlight)

SET(CMAKE_C_COMPILER mingw32-gcc)
SET(CMAKE_CXX_COMPILER mingw32-g++)
include_directories(C:/Users/mwang9/Downloads/Tool/SDL2-2.0.10/i686-w64-mingw32/include/SDL2)
link_directories(C:/Users/mwang9/Downloads/Tool/SDL2-2.0.10/i686-w64-mingw32/lib)
SET(EXECUTABLE_OUTPUT_PATH ../executable)  


add_executable( trafficlight button.cpp roadled.cpp task.cpp main.cpp led.cpp)
target_link_libraries(trafficlight  mingw32 SDL2_image SDL2main SDL2)