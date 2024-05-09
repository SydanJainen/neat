cmake_minimum_required(VERSION 3.10)

set (PROJECT_VERSION "1.0")
project(neat VERSION ${PROJECT_VERSION})
message( STATUS "Architecture: ${CMAKE_SYSTEM_PROCESSOR}" )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(CMAKE_BUILD_TYPE Debug)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 -O2")
endif (WIN32)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2")
endif (UNIX)

add_subdirectory(src)