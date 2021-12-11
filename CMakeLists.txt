cmake_minimum_required(VERSION 3.20)
project(spiejs_systiemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(spiejs_systiemo)

add_executable(spiejs_systiemo
        spiejs_systiemo/apogeum_finder.h
        spiejs_systiemo/params.h
        stdio_apogeum_finder_test.cpp)
