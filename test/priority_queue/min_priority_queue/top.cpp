#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../../../include/minimum/MinPriorityQueue.hpp"
#include "../../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using MinPriorityQueue = priority_queues::MinPriorityQueue<T, K>;


TEST(Min_Priority_Queue, Top_Insert_Reverse) {
    using std::make_shared;
    using std::size_t;

    constexpr size_t capacity = 0xFF;
    MinPriorityQueue<int, long> queue(capacity);

    std::array<int, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        queue.push(key, value);
    }

    for (int i = 0; i < capacity - 1; ++i) {
        queue.pop();
        EXPECT_EQ(*queue.top(), (i + 1));
    }

}

TEST(Min_Priority_Queue, Top_Insert_Order) {
    using std::make_shared;
    using std::size_t;

    const size_t capacity = 0xFF;
    MinPriorityQueue<int, long> queue(capacity);

    std::array<int, capacity> values{};

    for (size_t i = 0; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<int>(values[i]);
        queue.push(key, value);
        EXPECT_EQ(*queue.top(), values[i]);
    }
}