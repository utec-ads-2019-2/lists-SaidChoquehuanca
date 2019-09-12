#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            return ForwardIterator(other.current);

            // TODO
        }

        bool operator!=(ForwardIterator<T> other) {
            return this->current!=other.current;

            // TODO
        }

        ForwardIterator<T> operator++() {
            this->current = this->current->next;
            return *this;
            // TODO
        }

        T operator*() {
            return this->current->data;

            // TODO
        }
};

#endif