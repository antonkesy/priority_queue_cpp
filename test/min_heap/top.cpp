#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <array>
#include "../utility/IntegerKey.hpp"

using IntegerKey = priority_queues::IntegerKey;
template<typename T, typename K>
using BinaryMinHeap = priority_queues::minimum::BinaryMinHeap<T, K>;


TEST(Min_Heap, Top_Insert_Reverse) {
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

    for (int i = 0; i < capacity - 1; ++i) {
        min_heap.pop();
        EXPECT_EQ(*min_heap.top(), (i + 1));
    }

}

TEST(Min_Heap, Top_Insert_Order) {
    using std::make_shared;
    using std::size_t;

    const size_t capacity = 0xFF;
    BinaryMinHeap<int, long> min_heap(capacity);

    std::array<int, capacity> values{};

    for (size_t i = 0; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<int>(values[i]);
        min_heap.push(key, value);
        EXPECT_EQ(*min_heap.top(), values[i]);
    }
}