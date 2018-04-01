#ifndef HEAP
#define HEAP
#include <iostream>
using namespace std;

template<typename T>
class Heap {
private:
	vector<T> vec;

	inline int parent(int x) {
		return (x - 1) / 2;
	}

	inline int left(int x) {
		return x * 2 + 1;
	}

	inline int right(int x) {
		return x * 2 + 2;
	}

	void heapify_up(int idx) {
		int p = parent(idx);
		if (idx && vec[p] < vec[idx]) {
			swap(vec[p], vec[idx]);
			heapify_up(p);
		}
	}

	void heapify_down(int idx) {
		int l = left(idx), r = right(idx);
		int largest = idx;

		if (l < size() && vec[l] > vec[idx]) {
			largest = l;
		}

		if (r < size() && vec[r] > vec[largest]) {
			largest = r;
		}

		if (largest != idx) {
			swap(vec[largest], vec[idx]);
			heapify_down(largest);
		}
	}

public:
	Heap() {}
	Heap(vector<T> vec) : vec(vec) { maintain(); }

	int size() {
		return vec.size();
	}

	T top() {
		return vec[0];
	}

	T pop() {
		T ret = top();

		vec[0] = vec.back();
		vec.pop_back();
		heapify_down(0);

		return ret;
	}

	void push(T val) {
		vec.push_back(val);
		heapify_up(vec.size() - 1);
	}

	void maintain() {
		for (int i = parent(size()); i >= 0; --i) {
			heapify_down(i);
		}
	}
};

#endif