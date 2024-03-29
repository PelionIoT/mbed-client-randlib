/*
 * Copyright (c) 2021 Pelion. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TEST_RANDLIB_H
#define TEST_RANDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool test_randLIB_seed_random();

bool test_randLIB_get_8bit();

bool test_randLIB_get_16bit();

bool test_randLIB_get_32bit();

bool test_randLIB_get_64bit();

bool test_randLIB_get_n_bytes_random();

bool test_randLIB_get_random_in_range();

bool test_randLIB_randomise_base();


#ifdef __cplusplus
}
#endif

#endif // TEST_RANDLIB_H

