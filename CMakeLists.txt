cmake_minimum_required(VERSION 3.20)
project(spiejs_systiemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(spiejs_systiemo)

add_executable(stdio_apg_find
        spiejs_systiemo/apogeum_finder.h
        spiejs_systiemo/params.h
        spiejs_systiemo/cyclic_que.h
        stdio_apogeum_finder_test.cpp)

add_executable(cyclic_que_test
        spiejs_systiemo/apogeum_finder.h
        spiejs_systiemo/params.h
        spiejs_systiemo/cyclic_que.h cyclic_tab_test.cpp spiejs_systiemo/noise_filter.h)