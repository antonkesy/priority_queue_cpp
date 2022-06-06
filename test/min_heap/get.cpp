#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include "../utility/IntegerKey.hpp"

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;

int get_insert_reverse() {
    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<size_t, long> min_heap(capacity);

    array<size_t, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = capacity - i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<size_t>(values[i]);
        min_heap.push(key, value);
        auto result = min_heap.get(key);
        if (!result.has_value()) return EXIT_FAILURE;
        if (*result.value() != values[i]) return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int main() {
    return get_insert_reverse();
}