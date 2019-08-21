#pragma once
#include "pqueue-dllist.h"

DllPQueue::~DllPQueue()
{
	while (pTop != nullptr)
	{
		Node* tmp = pTop;
		pTop = pTop->pNext;
		tmp->pPrev = nullptr;
		tmp->pNext = nullptr;
		delete tmp;
	}
}

DllPQueue* DllPQueue::Merge(DllPQueue* one, DllPQueue* two)
{
	int n = two->length;
	for (int i = 0; i < n; i++ )
	{
		one->Enqueue(two->ExtractMin());
	}
	return one;
}

void DllPQueue::Print()
{
	std::cout << std::endl << "Doubly Linked List contents:" << std::endl << "(" << std::endl;
	Node* pRunner = pTop;
	while (pRunner != nullptr)
	{
		std::cout << pRunner->str << ",";
		pRunner = pRunner->pNext;
	}
	std::cout << "\n";
}

void DllPQueue::Deflate(bool print)
{
	std::cout << "\nDeflating the dllist queue\n";
	while (length > 0)
	{
		if (print)
		{
			std::cout << ExtractMin() << ", ";
		}
		else
		{
			std::string tmp = ExtractMin();
		}
	}
}

void DllPQueue::Enqueue(const std::string& elem)
{
	if (length == 0)
	{
		pTop = new Node(elem);
		length++;
	}
	else
	{
		Node* pRunner = pTop;
		while (pRunner != nullptr)
		{
			if (pRunner->pPrev == nullptr && (elem <= pRunner->str)) //special case: add before first node
			{
				pTop = new Node(elem, nullptr, pRunner);
				length++;
				pRunner->pPrev = pTop;
				pRunner = nullptr;

			}
			else if (pRunner->pNext == nullptr && (elem > pRunner->str)) //special case: add after last node
			{
				pRunner->pNext = new Node(elem, pRunner, nullptr);
				length++;
				pRunner = nullptr;
			}
			else if (elem <= pRunner->str) //add between nodes
			{
				Node* pNew = new Node(elem, pRunner->pPrev, pRunner);
				length++;
				pRunner->pPrev->pNext = pNew;
				pRunner->pPrev = pNew;
				pRunner = nullptr;
				pNew = nullptr;
			}
			if (pRunner != nullptr)
			{
				pRunner = pRunner->pNext;
			}
		}
	}
}

std::string DllPQueue::ExtractMin()
{
	if (length == 0)
	{
		return "";
	}
	std::string tmp = pTop->str;
	if (length == 1)
	{
		delete pTop;
		pTop = nullptr;
		length = 0;
	}
	else
	{
		Node* pRunner = pTop;
		pTop = pTop->pNext;
		pTop->pPrev = nullptr;
		length--;

		pRunner->pNext = nullptr;
		delete pRunner;
	}
	return tmp;
}

std::string DllPQueue::Peek() const
{
	return pTop->str;
}
