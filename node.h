#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf() {
        //Si no setteas a null en los push, va a fallar
        if(next != NULL)
            next->killSelf();
        delete this;
    }
};

#endif