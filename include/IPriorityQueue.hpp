#ifndef PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
#define PRIORITY_QUEUE_IPRIORITYQUEUE_HPP

#include <cstddef>
#include <memory>
#include <optional>
#include "IKey.hpp"

namespace priority_queues {


    template<typename T, typename K>
    class IPriorityQueue {
    public:
        virtual bool push(std::shared_ptr<IKey<K>> key, std::shared_ptr<T> value) = 0;

        virtual std::shared_ptr<T> top() = 0;

        virtual std::shared_ptr<T> pop() = 0;

        virtual void decreaseKey(std::shared_ptr<IKey<K>> key_to_decrease, std::shared_ptr<IKey<K>> new_key) = 0;

        virtual std::optional<std::shared_ptr<T>> get(std::shared_ptr<IKey<K>> key_to_find) = 0;
    };
}

#endif //PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
