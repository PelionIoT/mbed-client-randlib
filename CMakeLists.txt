#################################################################################
## Copyright 2020-2021 Pelion.
##
## SPDX-License-Identifier: Apache-2.0
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##     http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
#################################################################################

cmake_minimum_required (VERSION 3.14)
SET(CMAKE_SYSTEM_NAME Generic)

include(FindUnixCommands)

project(mbedRandLib)

option(enable_coverage_data "Enable Coverage data" OFF)

include(repositories.cmake)

add_library(mbedRandLib STATIC)
target_sources(mbedRandLib PRIVATE source/randLIB.c)

target_include_directories(mbedRandLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib)

add_definitions(-DINDEPENDENT_RANDLIB)

# Tests after this line
enable_testing()

if (enable_coverage_data)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif ()

add_executable(randlib_test
    source/randLIB.c
    test/randlib/randlibtest.cpp
    test/randlib/test_randlib.c
    test/stubs/random_stub.c
)

target_compile_options(randlib_test PRIVATE -DRANDLIB_PRNG)

target_include_directories(randlib_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib)
target_include_directories(randlib_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
target_include_directories(randlib_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test/randlib)

target_link_libraries(
    randlib_test
    gtest_main
)

# GTest framework requires C++ version 11
set_target_properties(randlib_test
PROPERTIES
    CXX_STANDARD 11
)

include(GoogleTest)
gtest_discover_tests(randlib_test)

if (enable_coverage_data AND ${CMAKE_PROJECT_NAME} STREQUAL mbedRandLib)
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html")

    add_test(NAME randlib_cov WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${BASH} -c "gcovr -r . -e ${CMAKE_CURRENT_SOURCE_DIR}/build -e '.*test.*' --html --html-details -o build/html/example-html-details.html"
    )
endif ()
