#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using BinaryMinHeap = priority_queues::minimum::BinaryMinHeap<T, K>;


TEST(Min_Heap, Decrease_Key_Last) {
    using std::make_shared;
    using std::size_t;

    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<int, long> min_heap(capacity);

    std::array<int, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        min_heap.push(key, value);
    }

    for (size_t i = 0U; i < capacity; ++i) {
        int new_key_value = 0 - (int) i - 1;
        auto key = make_shared<IntegerKey>(new_key_value);
        auto biggest_key = make_shared<IntegerKey>(capacity - i - 1);
        auto index = min_heap.index_of(biggest_key);
        EXPECT_TRUE(index.has_value());
        min_heap.decreaseKey(index.value(), key);
        EXPECT_EQ(*min_heap.top(), (capacity - i - 1));
    }
}