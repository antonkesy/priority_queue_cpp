#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using MinPriorityQueue = priority_queues::MinPriorityQueue<T, K>;


TEST(Min_Priority_Queue, Get_Insert_Reverse) {
    using std::make_shared;
    using std::size_t;

    constexpr size_t capacity = 0xFF;
    MinPriorityQueue<size_t, long> queue(capacity);

    std::array<size_t, capacity> values{};

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