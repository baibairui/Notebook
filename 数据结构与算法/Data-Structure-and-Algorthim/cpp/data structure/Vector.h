#include<iostream>
#include <algorithm> 
#include <stdexcept>

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class my_vector {
private:
    T* arr;
    size_t size;
    size_t cap;

    void resize() {
        size_t newCap = (cap == 0) ? 2 : cap * 2;
        T* newArr = new T[newCap](); // 初始化新数组
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = std::move(arr[i]);
        }
        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

public:
    my_vector() : arr(nullptr), size(0), cap(0) {}
    my_vector(size_t newcap) : arr(new T[newcap]()), size(0), cap(newcap) {}
    my_vector(size_t newcap, const T& data) : arr(new T[newcap]()), size(newcap), cap(newcap) {
        std::fill_n(arr, size, data);
    }
    my_vector(const my_vector& other) : arr(new T[other.cap]), size(other.size), cap(other.cap) {
        std::copy(other.arr, other.arr + size, arr);
    }
    my_vector(my_vector&& other) noexcept : arr(other.arr), size(other.size), cap(other.cap) {
        other.arr = nullptr;
        other.size = 0;
        other.cap = 0;
    }
    my_vector& operator=(const my_vector& other) {
        if (this != &other) {
            T* newArr = new T[other.cap];
            std::copy(other.arr, other.arr + other.size, newArr);
            delete[] arr;
            arr = newArr;
            size = other.size;
            cap = other.cap;
        }
        return *this;
    }
    my_vector& operator=(my_vector&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            cap = other.cap;
            other.arr = nullptr;
            other.size = 0;
            other.cap = 0;
        }
        return *this;
    }
    ~my_vector() {
        delete[] arr;
    }

    void push_back(const T& newdata) {
        if (size == cap) resize();
        arr[size++] = newdata;
    }
    void push_front(const T& newdata) {
        if (size == cap) resize();
        for (size_t i = size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = newdata;
        ++size;
    }
    void pop_back() {
        if (size == 0) throw std::out_of_range("Vector is empty");
        --size;
    }
    void pop_front() {
        if (size == 0) throw std::out_of_range("Vector is empty");
        for (size_t i = 0; i < size - 1; ++i) {
            arr[i] = std::move(arr[i + 1]);
        }
        --size;
    }
    size_t getsize() const {
        return size;
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return arr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return arr[index];
    }
};

#endif // VECTOR_H

