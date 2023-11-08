cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH cmake)

project(delegate)

add_executable(delegate main.cpp src/Object.cpp src/Delegate.cpp)

include_directories(include)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

