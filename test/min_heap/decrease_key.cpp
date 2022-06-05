#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include "../utility/IntegerKey.hpp"
#include <cstdlib>

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;

int decrease_last() {
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
        if (!index.has_value())
            return EXIT_FAILURE;
        min_heap.decreaseKey(index.value(), key);
        int top_value = *min_heap.top();
        if (top_value != (capacity - i - 1)) {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int main() {
    return decrease_last();
}