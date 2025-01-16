cmake_minimum_required(VERSION 3.12)
project(wfc VERSION 0.0.0 LANGUAGES CXX)

add_executable(wfc src/main.cpp src/tile.h)
target_compile_features(wfc PRIVATE cxx_std_20)
