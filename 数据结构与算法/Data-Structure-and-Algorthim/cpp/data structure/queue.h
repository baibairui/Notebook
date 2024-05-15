#include"Vector.h"
#include<iostream>


template<typename T>
class queue {
private:
	my_vector<T>data;
	

public:
	queue() {
		data = my_vector<T>();
	}
	queue(size_t newcap) {
		data = my_vector(newcap);
	}
	~queue() {
		data.~my_vector();
	}
	T top() {
		return data[0];
	}
	void pop() {
		data.pop_front();
	}
	void push(const T& newdata) {
		data.push_back(newdata);
	}
	size_t getsize() {
		return data.getsize();
	}
	bool isempty() {
		return data.getsize() == 0;
	}
};
