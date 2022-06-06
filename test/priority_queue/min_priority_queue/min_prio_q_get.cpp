#include <cstdlib>
#include <gtest/gtest.h>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;


TEST(Min_Priority_Queue, Get_Insert_Reverse) {
    constexpr size_t capacity = 0xFF;
    MinPriorityQueue<size_t, long> queue(capacity);

    array<size_t, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = capacity - i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<size_t>(values[i]);
        queue.push(key, value);
        auto result = queue.get(key);
        EXPECT_TRUE(result.has_value());
        EXPECT_EQ(*result.value(), values[i]);
    }
}