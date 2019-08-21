#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class HeapPQueue
{
public:
	HeapPQueue();
	~HeapPQueue();
	HeapPQueue(HeapPQueue& source);
	HeapPQueue& operator=(HeapPQueue& source);
	static HeapPQueue* Merge(HeapPQueue* one, HeapPQueue* two);

public: //public helper functions (not part of assignment)
	void Print();
	void Print2();
	void Deflate(bool print);

public: //assignment's interface functions
	void Enqueue(const std::string& elem);
	int GetLength()
	{
		return count;
	}
	std::string ExtractMin();
	std::string Peek() const;

private: //private helper functions
	void ExpandCapacity();
	void Swap(int index1, int index2);
	void Heapify(int index);

private: //member variables
	std::string* entries = nullptr;
	int capacity = INITIAL_CAPACITY;
	int count = 0;
	static constexpr int INITIAL_CAPACITY = 1;
};
