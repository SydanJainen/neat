cmake_minimum_required(VERSION 3.10)
project(neat-cli)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(neat)

set(SOURCE_DIR main.cpp)

add_executable(neat-cli main.cpp)

target_link_libraries(neat-cli neat)

install(TARGETS neat-cli DESTINATION bin)
