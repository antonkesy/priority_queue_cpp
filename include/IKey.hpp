#ifndef PRIORITY_QUEUE_IKEY_HPP
#define PRIORITY_QUEUE_IKEY_HPP

namespace priority_queues {
    template<typename K>
    class IKey {
    public:
        virtual int compareTo(IKey &other) = 0;

        virtual K getValue() = 0;

        virtual bool operator<(IKey<K> &other) = 0;

        virtual bool operator>(IKey<K> &other) = 0;
    };
}

#endif //PRIORITY_QUEUE_IKEY_HPP
