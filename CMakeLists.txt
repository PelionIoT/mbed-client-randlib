cmake_minimum_required (VERSION 3.11)
SET(CMAKE_SYSTEM_NAME Generic)

project(mbedRandLib)

add_library(mbedRandLib STATIC)
target_sources(mbedRandLib PRIVATE source/randLIB.c)
add_dependencies(mbedRandLib nshalpal)
target_link_libraries(mbedRandLib nshalpal)

target_include_directories(mbedRandLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib)
