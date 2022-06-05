#ifndef PRIORITY_QUEUE_INTEGERKEY_HPP
#define PRIORITY_QUEUE_INTEGERKEY_HPP

#include "../../include/IPriorityQueue.hpp"

namespace priority_queues {

    class IntegerKey : public IKey<long> {

    public:
        explicit IntegerKey(long value) : value_(value) {}

        int compareTo(IKey<long> &other) override {
            return (int) this->value_ - (int) other.getValue();
        }

        long getValue() override {
            return value_;
        }

        bool operator<(IKey<long> &other) override {
            return compareTo(other) > 0;
        }

        bool operator>(IKey<long> &other) override {
            return compareTo(other) < 0;
        }

    private:
        long value_;
    };

}

#endif //PRIORITY_QUEUE_INTEGERKEY_HPP
