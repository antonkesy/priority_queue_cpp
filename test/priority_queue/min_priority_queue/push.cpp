#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using MinPriorityQueue = priority_queues::MinPriorityQueue<T, K>;


TEST(Min_Priority_Queue, Push_Capacity) {
    using std::make_shared;
    using std::size_t;

    const int capacity = 5U;
    MinPriorityQueue<int, long> queue(capacity);

    std::array<int, capacity> values{};

    for (int i = 0; i < capacity; ++i) {
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        EXPECT_TRUE(queue.push(key, value));
    }
    auto key = make_shared<IntegerKey>(0);
    auto value = make_shared<int>(values[capacity]);
    EXPECT_FALSE(queue.push(key, value));

    key = make_shared<IntegerKey>(capacity);
    EXPECT_FALSE(queue.push(key, value));
}