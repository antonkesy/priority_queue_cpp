#ifndef PRIORITY_QUEUE_IMINIMUMCOLLECTION_HPP
#define PRIORITY_QUEUE_IMINIMUMCOLLECTION_HPP

#include <cstddef>
#include <memory>
#include <optional>
#include "../../IPriorityQueue.hpp"

namespace priority_queues::minimum {

    using priority_queues::IKey;

    template<typename T, typename K>
    class IMinimumCollection {
    public:
        virtual bool push(std::shared_ptr<IKey<K>> key, std::shared_ptr<T> value) = 0;

        virtual std::shared_ptr<T> top() = 0;

        virtual std::shared_ptr<T> pop() = 0;

        virtual void decreaseKey(std::size_t &key_to_decrease, std::shared_ptr<IKey<K>> new_key) = 0;

        virtual std::optional<std::size_t> index_of(std::shared_ptr<IKey<K>> key_to_find) = 0;

        virtual std::optional<std::shared_ptr<T>> get(std::shared_ptr<IKey<K>> key_to_find) = 0;
    };

}

#endif //PRIORITY_QUEUE_IMINIMUMCOLLECTION_HPP
