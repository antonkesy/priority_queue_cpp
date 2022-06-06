#include <gtest/gtest.h>
#include "../IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;

TEST(Integer_Key, Compare) {
    IntegerKey a(10);
    IntegerKey b(11);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);
}
