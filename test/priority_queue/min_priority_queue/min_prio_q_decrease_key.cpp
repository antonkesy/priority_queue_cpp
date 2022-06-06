#include <cstdlib>
#include <gtest/gtest.h>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using namespace priority_queues;
using std::make_shared;
using std::array;
using std::size_t;

TEST(Min_Priority_Queue, Decrease_Key_Last) {
    constexpr size_t capacity = 0xFF;
    MinPriorityQueue<int, long> queue(capacity);

    array<int, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        queue.push(key, value);
    }

    for (size_t i = 0U; i < capacity; ++i) {
        int new_key_value = 0 - (int) i - 1;
        auto key = make_shared<IntegerKey>(new_key_value);
        auto biggest_key = make_shared<IntegerKey>(capacity - i - 1);
        queue.decreaseKey(biggest_key, key);
        EXPECT_EQ(*queue.top(), (capacity - i - 1));
    }
}