#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class DllPQueue 
{
public:
	DllPQueue() = default;
	~DllPQueue();
	static DllPQueue* Merge(DllPQueue* one, DllPQueue* two);

public: //public helper functions (not part of assignment)
	void Print();
	void Print2()
	{
		Print();
	}
	void Deflate(bool print);

public: //assignment's interface functions
	void Enqueue(const std::string& elem);
	int GetLength()
	{
		return length;
	}
	std::string ExtractMin();
	std::string Peek() const;

private: //data and helper methods
	class Node
	{
	public:
		Node() = default;
		Node(const std::string& elem)
			:
			str(elem)
		{
		}
		Node(const std::string& elem,  Node* pPrev, Node* pNext)
			:
			str(elem),
			pPrev(pPrev),
			pNext(pNext)
		{
		}
	public:
		std::string str;
		Node* pPrev = nullptr;
		Node* pNext = nullptr;
	};

	Node* pTop = nullptr;
	int length = 0;
};