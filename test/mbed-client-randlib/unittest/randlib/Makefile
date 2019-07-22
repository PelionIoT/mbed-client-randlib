# Copyright (c) 2019 ARM Limited
# SPDX-License-Identifier: Apache-2.0
include ../makefile_defines.txt

COMPONENT_NAME = randLIB_unit

#This must be changed manually
SRC_FILES = \
        ../../../../source/randLIB.c

TEST_SRC_FILES = \
	main.cpp \
        randlibtest.cpp \
        test_randlib.c \
        ../stubs/random_stub.c \

include ../MakefileWorker.mk

CPPUTESTFLAGS += -DFEA_TRACE_SUPPORT -DRANDLIB_PRNG

