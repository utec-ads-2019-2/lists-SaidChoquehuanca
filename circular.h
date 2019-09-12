#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
                this->head->prev = node;
                this->head = node;
                this->nodes++;
                this->tail->next=this->head;
                this->head->prev=this->tail;
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
                node->prev  = this->tail;
                this->tail = node;
                this->nodes++;
                this->tail->next=this->tail;
                this->head->prev=this->head;
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
                    this->head->prev = nullptr;
                    delete deleted;
                    this->nodes--;
                    this->tail->next=this->tail;
                    this->head->prev=this->head;
                }
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
                    this->tail = nuevotail;
                    this->tail->next = nullptr;
                    delete oldtail;
                    this->nodes--;
                    this->tail->next=this->tail;
                    this->head->prev=this->head;
                }
            }
            // TODO
        }

        T operator[](int index) {
            int newindex = index%this->nodes;
            Node<T> *temp = this->head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->data;
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
            this->tail->next = 0;
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
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);

            // TODO
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail->next);

            // TODO
        }

        void merge(CircularLinkedList<T> list) {
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