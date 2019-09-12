#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if(this->nodes == 0){
                throw "No header";
            }
            return this->head->data;
            // TODO
        }

        T back() {
            if(this->nodes == 0){
                throw "No tail";
            }
            return this->tail->data;
            // TODO
        }

        void push_front(T value) {
            Node<T>* node = new Node<T>;
            node->data = value;
            if(this->nodes == 0){
                this->head = node;
                this->tail = this->head;
                this->nodes++;
            } else{
                node->next = this->head;
                this->head = node;
                this->nodes++;
            }
            // TODO
        }

        void push_back(T value) {
            Node<T>* node = new Node<T>;
            node->data = value;
            if (this->nodes == 0){
                this->head = node;
                this->tail = this->head;
                this->nodes++;
            } else {
                this->tail->next = node;
                this->tail = node;
                this->nodes++;
            }
            // TODO
        }

        void pop_front() {
            if (this->nodes == 0){
                throw "No elements";
            }else{
                if (this->nodes == 1){
                    delete this->head;
                    this->head = nullptr;
                    this->tail= nullptr;
                    this->nodes--;
                }else{
                    Node<T> *deleted = this->head;
                    this->head = this->head->next;
                    delete deleted;
                    this->nodes--;}
            }
            // TODO
        }

        void pop_back() {
            if(this->nodes == 0){
                throw  "No elements";
            }else{
                if (this->nodes == 1){
                    delete this->head;
                    this->head = nullptr;
                    this->tail= nullptr;
                    this->nodes--;
                }else{
                    Node<T> *oldtail = this->tail;
                    Node<T> *nuevotail = this->tail->prev;
                    for (int i = 1; i < this->nodes-1 ; i++) {
                        nuevotail = nuevotail->next;
                    }
                    this->tail = nuevotail;
                    delete oldtail;
                    this->nodes--;
                }
            }
            // TODO
        }

        T operator[](int index) {
            if(index>=this->nodes){
                throw "Exceso de nudos";
            }else {
                Node<T> *temp = this->head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp->data;
            }
            // TODO
        }

        bool empty() {
            return this->nodes==0;

            // TODO
        }

        int size() {
            return this->nodes;

            // TODO
        }

        void clear() {
            this->head->killSelf();
            this->nodes = 0;

            // TODO
        }

        void sort() {
            int size = this->nodes;
            int array[size];
            Node<T>*it = this->head;
            for (int i = 0; i <size ; ++i) {
                array[i] = it->data;
                it = it->next;
            }
            for (int i = (size)/2; i >0 ; i /=2) {
                for (int j = i; j < size; j++) {
                    int temp = array[j];
                    int k;
                    for ( k = j; k >=i  && array[k-i]>temp; k -=i) {
                        array[k] = array[k-i];
                    }
                    array[k] = temp;
                }
            }
            it = this->head;
            for (int l = 0; l < size ; l++) {
                it->data = array[l];
                it = it->next;
            }
            // TODO
        }
    
        void reverse() {
            int size = this->nodes;
            int *array= new int [size];
            Node<T>*it = this->head;
            for (int i = 0; i <size ; ++i) {
                array[i] = it->data;
                it = it->next;
            }
            it = this->head;
            for (int j = size-1; j >=0 ; j--) {
                it->data = array[j];
                it = it->next;
            }
            // TODO
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);

            // TODO
        }

	    ForwardIterator<T> end() {
            return ForwardIterator<T>(this->tail->next);

            // TODO
        }

        void merge(ForwardList<T> list) {
            int size= list.nodes;
            Node<T> *it= list.head;
            for (int i = 0; i <size ; i++) {
                this->push_back(it->data);
                it = it->next;
            }
            // TODO
        }
};

#endif