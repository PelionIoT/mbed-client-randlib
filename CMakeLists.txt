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

cmake_minimum_required (VERSION 3.11)
SET(CMAKE_SYSTEM_NAME Generic)

project(mbedRandLib)

add_library(mbedRandLib STATIC)
target_sources(mbedRandLib PRIVATE source/randLIB.c)
add_dependencies(mbedRandLib nshalpal)
target_link_libraries(mbedRandLib nshalpal)

target_include_directories(mbedRandLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib)
target_include_directories(mbedRandLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib/platform)
