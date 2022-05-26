#ifndef PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
#define PRIORITY_QUEUE_IPRIORITYQUEUE_HPP

#include <cstddef>

namespace priority_queue {

    template<class T>
    class IPriorityQueue {
    public:
        virtual bool push(std::size_t key, T *value) = 0;

        virtual T *top() = 0;

        virtual T *pop() = 0;

        virtual bool decreaseKey(std::size_t key_to_decrease, std::size_t new_key_value) = 0;
    };
}

#endif //PRIORITY_QUEUE_IPRIORITYQUEUE_HPP
