#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using BinaryMinHeap = priority_queues::minimum::BinaryMinHeap<T, K>;


TEST(Min_Heap, Get_Insert_Reverse) {
    using std::make_shared;
    using std::size_t;

    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<size_t, long> min_heap(capacity);

    std::array<size_t, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = capacity - i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<size_t>(values[i]);
        min_heap.push(key, value);
        auto result = min_heap.get(key);
        EXPECT_TRUE(result.has_value());
        EXPECT_EQ(*result.value(), values[i]);
    }
}