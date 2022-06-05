#ifndef PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
#define PRIORITY_QUEUE_IPRIORITYQUEUE_HPP

#include <cstddef>
#include <memory>

namespace priority_queues {

    template<typename T>
    class IKey {
    public:
        virtual int compareTo(IKey &other) = 0;

        virtual T getValue() = 0;

        virtual bool operator<(IKey<T> &other) = 0;

        virtual bool operator>(IKey<T> &other) = 0;

    };

    template<typename T, typename K>
    class IPriorityQueue {
    public:
        virtual bool push(IKey<K> &key, T &value) = 0;

        virtual std::shared_ptr<T> top() = 0;

        virtual std::shared_ptr<T> pop() = 0;

        virtual void decreaseKey(IKey<K> &key_to_decrease, IKey<K> &newKey) = 0;
    };
}

#endif //PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
