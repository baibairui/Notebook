#pragma once
#include"Vector.h"

template<typename T>
class stack {
private:
    my_vector<T> data;

public:
    stack() : data() {}
    stack(size_t cap) : data(cap) {}
    stack(size_t cap, T data) : data(cap, data) {}

    bool isempty() const {
        return data.getsize() == 0;
    }

    void push(T newdata) {
        data.push_front(newdata);
    }

    void pop() {
        if (isempty()) throw std::runtime_error("Stack underflow");
        data.pop_front(); // Assume that Vector has pop_back method
    }

    T top() const {
        if (isempty()) throw std::runtime_error("Stack is empty");
        return data[data.getsize() - 1];
    }
};
