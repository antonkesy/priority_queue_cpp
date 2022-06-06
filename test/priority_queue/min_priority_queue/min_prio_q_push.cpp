#include <cstdlib>
#include <gtest/gtest.h>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using namespace priority_queues::minimum;
using namespace priority_queues;
using std::make_shared;
using std::array;
using std::size_t;

TEST(Min_Priority_Queue, Push_Capacity) {
    const int capacity = 5U;
    MinPriorityQueue<int, long> queue(capacity);

    array<int, capacity> values{};

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