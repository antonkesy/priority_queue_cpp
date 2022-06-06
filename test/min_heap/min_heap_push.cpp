#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include "../utility/IntegerKey.hpp"

using namespace priority_queues::minimum;
using namespace priority_queues;
using std::make_shared;
using std::array;
using std::size_t;

TEST(Min_Heap, Push_Capacity) {
    const int capacity = 5U;
    BinaryMinHeap<int, long> min_heap(capacity);

    array<int, capacity> values{};

    for (int i = 0; i < capacity; ++i) {
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        EXPECT_TRUE(min_heap.push(key, value));
    }
    auto key = make_shared<IntegerKey>(0);
    auto value = make_shared<int>(values[capacity]);
    EXPECT_FALSE(min_heap.push(key, value));

    key = make_shared<IntegerKey>(capacity);
    EXPECT_FALSE(min_heap.push(key, value));
}