# Copyright (c) 2019 ARM Limited
# SPDX-License-Identifier: Apache-2.0
SRCS := $(wildcard source/*)
LIB := librand.a
EXPORT_HEADERS := mbed-client-randlib

include ../exported_rules.mk
