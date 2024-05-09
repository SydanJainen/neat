cmake_minimum_required(VERSION 3.10)
project(neat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(neat
    main.cpp
)

target_include_directories(neat PRIVATE "${CMAKE_SOURCE_DIR}/include")

install(TARGETS neat DESTINATION output)
