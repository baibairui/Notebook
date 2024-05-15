#include "Vector.h"
#include <iostream>
#include <algorithm> // 如果需要使用 std::swap

template<typename T>
class priority_queue {
private:
    my_vector<T> data;

    void swim() {
        int child = data.getsize() - 1;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (data[child] < data[parent]) {
                std::swap(data[child], data[parent]); 
                child = parent;
            }
            else {
                break;
            }
        }
    }

    void sink() {
        int parent = 0;
        int last = data.getsize() - 1;
        while (parent * 2 + 1 <= last) {
            int child = parent * 2 + 1;
            if (child < last && data[child + 1] < data[child]) {
                child++;
            }
            if (data[parent] > data[child]) {
                std::swap(data[parent], data[child]);
                parent = child;
            }
            else {
                break;
            }
        }
    }

public:
    priority_queue() {
        data = my_vector<T>();
    }
    T top() {
        if (data.getsize() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        return data[0];
    }

    void push(T newdata) {
        data.push_back(newdata);
        swim();
    }

    void pop() {
        if (data.getsize() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        data[0] = data[data.getsize() - 1];
        data.pop_back();
        if (data.getsize() > 0) {
            sink();
        }
    }
    bool isempty() {
        return data.getsize() == 0;
    }
};
