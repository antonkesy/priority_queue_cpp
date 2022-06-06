#ifndef PRIORITY_QUEUE_PRIORITYQUEUE_HPP
#define PRIORITY_QUEUE_PRIORITYQUEUE_HPP

#include <cstddef>
#include "../IPriorityQueue.hpp"
#include "collections/IMinimumCollection.hpp"
#include "collections/binary_heap/BinaryMinHeap.hpp"

namespace priority_queues {
    using namespace priority_queues::minimum;
    using std::make_unique;

    template<typename T, typename K>
    class MinPriorityQueue : public IPriorityQueue<T, K> {
    public:
        explicit MinPriorityQueue(size_t capacity)
                : minimumCollection_(make_unique<BinaryMinHeap<T, K>>

                                             (capacity)) {}

        virtual ~MinPriorityQueue() = default;

        bool push(std::shared_ptr<IKey<K>> key, std::shared_ptr<T> value) override {
            return minimumCollection_->push(key, value);
        }

        std::shared_ptr<T> top() override {
            return minimumCollection_->top();
        }

        std::shared_ptr<T> pop() override {
            return minimumCollection_->pop();
        }

        void decreaseKey(std::shared_ptr<IKey<K>> key_to_decrease, std::shared_ptr<IKey<K>> new_key) override {
            auto index = minimumCollection_->index_of(key_to_decrease);
            if (!index.has_value()) return;
            minimumCollection_->decreaseKey(index.value(), new_key);
        }

        std::optional<std::shared_ptr<T>> get(std::shared_ptr<IKey<K>> key_to_find) override {
            return minimumCollection_->get(key_to_find);
        }

    private:
        std::unique_ptr<IMinimumCollection<T, K>> minimumCollection_;
    };


}

#endif //PRIORITY_QUEUE_PRIORITYQUEUE_HPP
