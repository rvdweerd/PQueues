#pragma once
#include <string>
#include <iomanip>
#include <vector>
#include <iostream>

class VectorPQueue
{
public:
	VectorPQueue() = default;
	~VectorPQueue() = default;
	static VectorPQueue* Merge(VectorPQueue* one, VectorPQueue* two);

public: //public helper functions (not part of assignment)
	void Print();
	void Deflate(bool print);

public: //assignment's interface functions
	void Enqueue(const std::string& elem);
	int GetLength();
	std::string ExtractMin();
	std::string Peek() const;

private: //data and helper methods
	std::vector<std::string> vecQueue = {};
};

