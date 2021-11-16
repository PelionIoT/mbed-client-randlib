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
#include "gtest/gtest.h"
#include "test_randlib.h"

class randLIB : public testing::Test {
    void SetUp()
    {
    }

    void TearDown()
    {
    }
};

TEST_F(randLIB, test_randLIB_seed_random)
{
    ASSERT_TRUE(test_randLIB_seed_random());
}

TEST_F(randLIB, test_randLIB_get_8bit)
{
    ASSERT_TRUE(test_randLIB_get_8bit());
}

TEST_F(randLIB, test_randLIB_get_16bit)
{
    ASSERT_TRUE(test_randLIB_get_16bit());
}

TEST_F(randLIB, test_randLIB_get_32bit)
{
    ASSERT_TRUE(test_randLIB_get_32bit());
}

TEST_F(randLIB, test_randLIB_get_64bit)
{
    ASSERT_TRUE(test_randLIB_get_64bit());
}

TEST_F(randLIB, test_randLIB_get_n_bytes_random)
{
    ASSERT_TRUE(test_randLIB_get_n_bytes_random());
}

TEST_F(randLIB, test_randLIB_get_random_in_range)
{
    ASSERT_TRUE(test_randLIB_get_random_in_range());
}

TEST_F(randLIB, test_randLIB_randomise_base)
{
    ASSERT_TRUE(test_randLIB_randomise_base());
}
