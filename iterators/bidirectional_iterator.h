#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            // Estás creando un nuevo iterador
            return BidirectionalIterator(other.current);

            // TODO
        }

        bool operator!=(BidirectionalIterator<T> other) {
            return this->current!=other.current;

            // TODO
        }

        BidirectionalIterator<T> operator++() {
            // Caso vacío?
            this->current = this->current->next;
            return *this;
            // TODO
        }

        BidirectionalIterator<T> operator--() {
            // Caso vacío?
            this->current = this->current->prev;
            return *this;
            // TODO
        }

        T operator*() {
            // Caso vacío?
            return this->current->data;

            // TODO
        }
};

#endif