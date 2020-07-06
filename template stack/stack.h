#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

template <class T>
class stack {
    public: 
        stack();
        void push(T val);
        void pop();
        T top();
        bool empty();

    private:
        int size;
        T data[MAX_SIZE];

};  
    template <class T>
    stack<T>::stack() {
        size = 0;
    
    
    }
    template <class T>
    void stack<T>::push(T val) {
        if(size >= MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        if(empty()) {
            data[0] = val;
            size++;
        }
        else {
            data[size] = val;
            size++;
        }

    }

    template <class T>
    void stack<T>::pop() {
        if(empty()) {
            throw out_of_range("Called pop on empty stack.");
        }
        else {
            size--;
    }
}
    template <class T>
    T stack<T>::top() {
        if(empty()) {
            throw underflow_error("Called top on empty stack.");
        }
        else {
            return data[size-1];
        }
    }

    template <class T>
    bool stack<T>::empty() {
        if(size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

#endif