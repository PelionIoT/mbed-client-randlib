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
#include "test_randlib.h"
#include <string.h>
#include <inttypes.h>
#include "randLIB.h"

static uint32_t seed_value = 4;
static bool seed_inc = false;

static void random_stub_set_seed(uint32_t value, bool increment)
{
    seed_value = value;
    seed_inc = increment;
}

bool test_randLIB_seed_random()
{
    randLIB_reset();
    randLIB_seed_random();
    return true;
}

bool test_randLIB_get_8bit()
{
    randLIB_reset();
    randLIB_seed_random();
    uint8_t test = randLIB_get_8bit();
    if (test == 0) {
        test = randLIB_get_8bit();
        if (test == 0) {
            return false;
        }
    }
    return true;
}

bool test_randLIB_get_16bit()
{
    randLIB_reset();
    randLIB_seed_random();
    uint16_t test = randLIB_get_16bit();
    if (test == 0) {
        test = randLIB_get_16bit();
        if (test == 0) {
            return false;
        }
    }
    return true;
}

bool test_randLIB_get_32bit()
{
    randLIB_reset();
    randLIB_seed_random();
    uint32_t test = randLIB_get_32bit();
    if (test == 0) {
        test = randLIB_get_32bit();
        if (test == 0) {
            return false;
        }
    }
    return true;
}

static bool test_output(uint32_t seed, bool seed_inc, const uint64_t expected[8])
{
    random_stub_set_seed(seed, seed_inc);
    randLIB_reset();
    randLIB_seed_random();
    for (int i = 0; i < 8; i++) {
        if (randLIB_get_64bit() != expected[i]) {
            return false;
        }
    }

    return true;
}

bool test_randLIB_get_64bit()
{
    randLIB_reset();
    randLIB_seed_random();
    uint32_t test = randLIB_get_32bit();
    if (test == 0) {
        test = randLIB_get_32bit();
        if (test == 0) {
            return false;
        }
    }
    return true;
}

bool test_randLIB_get_n_bytes_random()
{
    randLIB_reset();
    randLIB_seed_random();

    uint8_t dat[5];
    void *ret = randLIB_get_n_bytes_random(dat, 5);
    if (ret != dat) {
        return false;
    }

    uint8_t dat2[5];
    randLIB_get_n_bytes_random(dat2, 5);
    if (memcmp(dat, dat2, 5) == 0) {
        return false;
    }

    return true;
}

bool test_randLIB_get_random_in_range()
{
    randLIB_reset();
    randLIB_seed_random();

    uint16_t ret = randLIB_get_random_in_range(2, 2);
    if (ret != 2) {
        return false;
    }

    ret = randLIB_get_random_in_range(2, 3);
    if (ret != 2 && ret != 3) {
        return false;
    }

    ret = randLIB_get_random_in_range(0, 0xFFFF);

    return true;
}

bool test_randLIB_randomise_base()
{
    randLIB_reset();
    randLIB_seed_random();

    uint32_t ret = randLIB_randomise_base(0, 0, 0);
    if (ret) {
        return false;
    }
    ret = randLIB_randomise_base(0xffff0000, 0x8888, 0x8888);
    if (ret != 0xffffffff) {
        return false;
    }
    return true;
}
