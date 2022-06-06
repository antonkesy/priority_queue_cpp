#include "../IMinimumCollection.hpp"
#include <vector>

namespace priority_queues::minimum {

    template<typename T, typename K>
    class BinaryMinHeap : public IMinimumCollection<T, K> {
    public:
        explicit BinaryMinHeap(const std::size_t &capacity) : capacity_(capacity), size_(0U) {
            elements_.resize(capacity_);
            for (auto &item: elements_)
                item = std::make_unique<Node>();

        }

        virtual ~BinaryMinHeap() = default;

        std::optional<std::size_t> index_of(std::shared_ptr<IKey<K>> key_to_find) override {
            for (size_t i = 0U; i < size_; ++i)
                if (elements_[i]->key->compareTo(*key_to_find) == 0)
                    return {i};
            return std::nullopt;
        }

        std::optional<std::shared_ptr<T>> get(std::shared_ptr<IKey<K>> key_to_find) override {
            auto index = index_of(key_to_find);
            if (index == std::nullopt) return std::nullopt;
            return {elements_[index.value()]->value};
        }

        bool push(std::shared_ptr<IKey<K>> key, std::shared_ptr<T> value) override {
            if (capacity_ == size_) return false;

            elements_[size_]->value = value;
            elements_[size_]->key = key;

            size_t s = size_;
            size_++;
            decreaseKey(s, key);

            return true;
        }

        std::shared_ptr<T> top() override {
            if (size_ == 0U) return nullptr;
            return elements_[0]->value;
        }

        std::shared_ptr<T> pop() override {
            if (size_ == 0U) return nullptr;

            //decrease size before once
            --size_;

            //1 element in queue
            if (size_ == 0U)
                return elements_[0]->value;

            //multiple elements in queue
            auto root_value = elements_[0]->value;
            std::swap(elements_[0], elements_[size_]);
            heapify(0);

            return root_value;
        }

        void decreaseKey(std::size_t &index_decrease, std::shared_ptr<IKey<K>> new_key) override {
            elements_[index_decrease]->key = new_key;
            if (size_ <= 1) return;

            while (index_decrease != 0 &&
                   (*elements_[parent_index(index_decrease)]->key) < (*elements_[index_decrease]->key)) {

                std::swap(elements_[index_decrease], elements_[parent_index(index_decrease)]);
                index_decrease = parent_index(index_decrease);
            }
        }

    private:
        struct Node {
            std::shared_ptr<IKey<K>> key;
            std::shared_ptr<T> value;
        };

        std::vector<std::unique_ptr<Node>> elements_;
        size_t size_;
        size_t capacity_;

        void heapify(size_t index) {
            size_t left = left_index(index);
            size_t right = right_index(index);
            size_t smallest = index;

            if (left < size_ && elements_[left]->key < elements_[index]->key)
                smallest = left;

            if (right < size_ && elements_[right]->key < elements_[smallest]->key)
                smallest = right;

            if (smallest != index) {
                std::swap(elements_[index], elements_[smallest]);
                heapify(smallest);
            }
        }

        static inline size_t left_index(size_t of) {
            return 2U * of + 1U;
        }

        static inline size_t right_index(size_t of) {
            return 2U * of + 2U;
        }

        static inline size_t parent_index(size_t of) {
            return (of - 1U) / 2U;
        }
    };
}