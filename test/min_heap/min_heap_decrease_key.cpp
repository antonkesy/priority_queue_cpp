#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include "../utility/IntegerKey.hpp"
#include <cstdlib>
#include <gtest/gtest.h>

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;

TEST(Decrease_Key, Decrease_Last) {
    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<int, long> min_heap(capacity);

    array<int, capacity> values{};

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