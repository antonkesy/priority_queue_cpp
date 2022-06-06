#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using BinaryMinHeap = priority_queues::minimum::BinaryMinHeap<T, K>;


TEST(Min_Heap, Push_Capacity) {
    using std::make_shared;
    using std::size_t;

    const int capacity = 5U;
    BinaryMinHeap<int, long> min_heap(capacity);

    std::array<int, capacity> values{};

    for (int i = 0; i < capacity; ++i) {
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        EXPECT_TRUE(min_heap.push(key, value));
    }
    auto value = make_shared<int>(0);

    auto key = make_shared<IntegerKey>(0);
    EXPECT_FALSE(min_heap.push(key, value));

    key = make_shared<IntegerKey>(capacity);
    EXPECT_FALSE(min_heap.push(key, value));
}