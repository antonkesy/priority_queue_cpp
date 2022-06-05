#include "../../include/minimum/collections/binary_heap/BinaryMinHeap.hpp"
#include <cstdlib>
#include "../utility/IntegerKey.hpp"

using namespace priority_queues;
using namespace priority_queues::minimum;
using std::make_shared;
using std::array;
using std::size_t;

int top_remove() {
    constexpr size_t capacity = 0xFF;
    BinaryMinHeap<int, long> min_heap(capacity);

    array<int, capacity> values{};

    for (size_t i = 0U; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(i);
        auto value = make_shared<int>(values[i]);
        min_heap.push(key, value);
    }

    for (int i = 0; i < capacity - 1; ++i) {
        min_heap.pop();

        int top_value = *min_heap.top();
        if (top_value != (i + 1))
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int top_insert() {
    const size_t capacity = 0xFF;
    BinaryMinHeap<int, long> min_heap(capacity);

    array<int, capacity> values{};

    for (size_t i = 0; i < capacity; ++i) {
        values[i] = (int) i;
        auto key = make_shared<IntegerKey>(capacity - i);
        auto value = make_shared<int>(values[i]);
        min_heap.push(key, value);

        if (*min_heap.top() != values[i])
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main() {
    return top_insert() & top_remove();
}