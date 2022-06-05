#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include "../utility/IntegerKey.hpp"
#include <cstdlib>

using namespace priority_queues::minimum;
using namespace priority_queues;
using std::make_shared;
using std::array;
using std::size_t;

int reach_capacity() {
    const int capacity = 5U;
    BinaryMinHeap<int, long> min_heap(capacity);

    array<int, capacity> values{};

    for (int i = 0; i < capacity; ++i) {
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        if (!min_heap.push(key, value))
            return EXIT_FAILURE;
    }
    auto key = make_shared<IntegerKey>(0);
    auto value = make_shared<int>(values[capacity]);
    if (min_heap.push(key, value))
        return EXIT_FAILURE;

    key = make_shared<IntegerKey>(capacity);
    if (min_heap.push(key, value))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int main() {
    return reach_capacity();
}