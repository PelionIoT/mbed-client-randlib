INCLUDE(CMakeForceCompiler)

cmake_minimum_required (VERSION 2.8)
SET(CMAKE_SYSTEM_NAME Generic)
 
project(mbedClientRandLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib/platform/)


FILE(GLOB MBED_CLIENT_RAND_LIB_SRC
	"${CMAKE_CURRENT_SOURCE_DIR}/source/*.c"
 	"${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib/*.h"
 	"${CMAKE_CURRENT_SOURCE_DIR}/mbed-client-randlib/platform/*.h"
	)

CREATE_LIBRARY(mbedClientRandLib "${MBED_CLIENT_RAND_LIB_SRC}" "") 


