#pragma once
#include "pqueue-vector.h"

VectorPQueue* VectorPQueue::Merge(VectorPQueue* one, VectorPQueue* two)
{
	one->vecQueue.insert(one->vecQueue.end(), two->vecQueue.begin(), two->vecQueue.end());
	return one;
}

void VectorPQueue::Print()
{
	std::cout << "Vector contents:" << std::endl << "( " ;
	for (std::string n : vecQueue) {
		std::cout << "  " << n << ',';
	}
	std::cout << ")" << std::endl;
	std::cout << std::endl;

}

void VectorPQueue::Deflate(bool print)
{
	int n = vecQueue.size();
	std::cout << "Deflating the vector queue\n";
	for (int i = 0; i < n; i++)
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
	std::cout << std::endl;
}

void VectorPQueue::Enqueue(const std::string& elem)
{
	vecQueue.push_back(elem);
}

int VectorPQueue::GetLength()
{
	return vecQueue.size();
}

std::string VectorPQueue::ExtractMin()
{
	std::string tmp = vecQueue[0];
	int index = 0;
	for (unsigned int i = 0; i < vecQueue.size(); i++)
	{
		if (vecQueue[i] < tmp)
		{
			tmp = vecQueue[i];
			index = i;
		}
	}
	vecQueue.erase(vecQueue.begin() + index);
	return tmp;
}

std::string VectorPQueue::Peek() const
{
	std::string tmp = vecQueue[0];
	for (unsigned int i = 0; i < vecQueue.size(); i++)
	{
		if (vecQueue[i] < tmp)
		{
			tmp = vecQueue[i];
		}
	}
	return tmp;
}
