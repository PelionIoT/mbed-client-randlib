#!/bin/bash
#
#################################################################################
## Copyright (c) 2021 Pelion. All rights reserved.
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
#
#
# Run unit tests and produce 'test_detail.xml' output to build folder.
#

TEST_DIR="build"

export GTEST_OUTPUT=xml
mkdir -p ${TEST_DIR}
cd ${TEST_DIR}
cmake .. -Denable_coverage_data=ON
make all test

# copy produced xml to top level
cp *.xml ..
