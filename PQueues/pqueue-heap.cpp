#pragma once
#include "pqueue-heap.h"

HeapPQueue::HeapPQueue()
	:
	entries(new std::string[INITIAL_CAPACITY])
{
}

HeapPQueue::~HeapPQueue()
{
	delete[] entries;
	entries = nullptr;
}

HeapPQueue::HeapPQueue(HeapPQueue& source)
{
	*this = source;
}

HeapPQueue& HeapPQueue::operator=(HeapPQueue& source)
{
	if (this != &source)
	{
		delete[] this->entries;
		this->count = source.count;
		this->capacity = source.capacity;
		this->entries = new std::string[capacity];

		for (int i = 0; i < count; i++)
		{
			this->entries[i] = source.entries[i];
		}
	}
	return *this;
}

HeapPQueue* HeapPQueue::Merge(HeapPQueue* one, HeapPQueue* two)
{
	HeapPQueue* oneOld = one;
	for (int j = 0; j < two->count; j++)
	{
		one->Enqueue(two->entries[j]);					//THIS IS THE EXPENSIVE EASY SOLUTION 
	}
	delete[] two->entries; two->entries = nullptr;
	return one;
}

void HeapPQueue::Print()
{
	std::cout << "Heap contents:" << std::endl << "(" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << entries[i] << ",";
	}
	std::cout << std::endl;
}

void HeapPQueue::Print2()
{
	// Quick & Dirty way to visualize the binary heap tree (works for small entries, up to depth of 4)
	// Did the job for me in testing, decided not to spend more time on perfecting this
	std::cout << "Heap contents:" << std::endl;
	float padding = 1.0f;
	int total_depth = int(log(count + 1) / log(2));
	for (int i = 0; i < count; i++)
	{
		int depth = int(log(i + 1) / log(2));
		std::cout << std::string( int( pow(2, (total_depth - depth) * padding)), '_') << entries[i] << ",";
		if ((int(log(i + 2) / log(2)) - depth) > 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

void HeapPQueue::Deflate(bool print)
{
	std::cout << "Deflating the heap queue\n";
	while (count > 0)
	{
		if (print)
		{
			std::cout << ExtractMin() << ", ";
		}
		else
		{
			ExtractMin();
		}
	}
	std::cout << std::endl << std::endl;
}

void HeapPQueue::Enqueue(const std::string& elem)
{
	if (count == capacity)
	{
		ExpandCapacity();
	}
	entries[count] = elem; //OR:  *(entries + count) = elem;
	count++;

	int runner = count;
	while ((runner / 2 != 0) && (entries[runner - 1] < entries[runner / 2 - 1]))
	{
		Swap(runner - 1, runner / 2 - 1);
		runner /= 2;
	}
}

std::string HeapPQueue::ExtractMin()
{
	std::string minstring = entries[0];
	entries[0] = entries[count - 1];
	count--;
	Heapify(0);
	return minstring;
}

std::string HeapPQueue::Peek() const
{
	return entries[0];
}

void HeapPQueue::ExpandCapacity()
{
	std::string* pOld = entries;
	capacity *= 2;
	entries = new std::string[capacity];
	for (int i = 0; i < count; i++)
	{
		entries[i] = pOld[i];
	}
	delete[] pOld;
	pOld = nullptr;
}

void HeapPQueue::Swap(int index1, int index2)
{
	std::string temp = entries[index1];
	entries[index1] = entries[index2];
	entries[index2] = temp;
}

void HeapPQueue::Heapify(int index)
{
	int runner = index + 1;
	if (count >= runner * 2 + 1)
	{
		//full node
		if ((entries[runner * 2 - 1] < entries[runner * 2]) && (entries[runner - 1] > entries[runner * 2 - 1]))
		{
			Swap(runner - 1, runner * 2 - 1);
			Heapify(runner * 2 - 1);
		}
		else if (entries[runner - 1] > entries[runner * 2])
		{
			Swap(runner - 1, runner * 2);
			Heapify(runner * 2);
		}
	}
	else if (count == runner * 2)
	{
		//half node
		if (entries[runner - 1] > entries[runner * 2 - 1])
		{
			Swap(runner - 1, runner * 2 - 1);
		}
	}
}



