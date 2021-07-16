/*
 * Copyright (c) 2016, 2018, 2021, Pelion and affiliates.
 */
#include "gtest/gtest.h"
#include "test_randlib.h"

class randLIB : public testing::Test
{
    void SetUp() {
    }

    void TearDown() {
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
