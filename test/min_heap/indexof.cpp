#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include "../utility/IntegerKey.hpp"

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;


TEST(Index_Of, Insert_Reverse) {
    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<size_t, long> min_heap(capacity);

    array<size_t, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = capacity - i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<size_t>(values[i]);
        min_heap.push(key, value);
        auto result = min_heap.index_of(key);
        EXPECT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), 0);
    }
}