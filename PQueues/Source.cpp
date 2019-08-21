#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include<fstream>
#include <vector>
#include "pqueue-vector.h"
#include "pqueue-heap.h"
#include "pqueue-dllist.h"
#include "conio.h"
#include "FrameTimer.h"

void TestVectorPQ()
{
	VectorPQueue vec;
	vec.Enqueue("ping");
	vec.Enqueue("pong");
	vec.Enqueue("Pang");
	vec.Enqueue("!Zebra");
	vec.Enqueue("pang");
	vec.Enqueue("@zzz");


	vec.Print();
	std::cout << "peek: " << vec.Peek() << std::endl;
	std::cin.get();

	std::cout << "erased: " << vec.ExtractMin() << std::endl;
	vec.Print();
	std::cout << "peek: " << vec.Peek() << std::endl;
	std::cin.get();

	std::cout << "erased: " << vec.ExtractMin() << std::endl;
	vec.Print();
	std::cout << "peek: " << vec.Peek() << std::endl;
	std::cin.get();

	std::cout << "erased: " << vec.ExtractMin() << std::endl;
	vec.Print();
	std::cout << "peek: " << vec.Peek() << std::endl;
	std::cin.get();

	std::cout << "erased: " << vec.ExtractMin() << std::endl;
	vec.Print();
	std::cin.get();
}
void TestInputs()
{
	VectorPQueue vecQ;
	HeapPQueue heapQ;
	DllPQueue dllQ;

	std::string input;

	std::cout << "\nString entry (Q = quit): ";
	std::cin >> input;

	while (input != "Q")
	{
		heapQ.Enqueue(input);
		vecQ.Enqueue(input);
		dllQ.Enqueue(input);

		std::cout << "\nString entry (Q = quit): ";
		std::cin >> input;
	}
	
	std::cout << "\n\nEnd Result:\n";
	heapQ.Print2();
	vecQ.Print();
	dllQ.Print();

	std::cout << "\nextracting two elements from dllqueue\n";
	std::cout << dllQ.ExtractMin();
	std::cout << dllQ.ExtractMin() << std::endl;

	std::cout << "\n";
	heapQ.Deflate(true);
	vecQ.Deflate(true);
	dllQ.Deflate(true);

}
void TestMerge()
{
	{
		HeapPQueue a; a.Enqueue("1");	a.Enqueue("2");	a.Enqueue("3");	a.Enqueue("3");	a.Enqueue("2");	a.Enqueue("1");
		HeapPQueue b; b.Enqueue("a");	b.Enqueue("b");	b.Enqueue("c");	b.Enqueue("c");	b.Enqueue("b");	b.Enqueue("a");
		a.Print2();
		b.Print2();
		HeapPQueue* c = a.Merge(&a, &b);
		c->Print2();
		c->Deflate(true);
	}

	{
		VectorPQueue a; a.Enqueue("1");	a.Enqueue("2");	a.Enqueue("3");	a.Enqueue("3");	a.Enqueue("2");	a.Enqueue("1");
		VectorPQueue b; b.Enqueue("a");	b.Enqueue("b");	b.Enqueue("c");	b.Enqueue("c");	b.Enqueue("b");	b.Enqueue("a");
		a.Print();
		b.Print();
		VectorPQueue* c = a.Merge(&a, &b);
		c->Print();
		c->Deflate(true);
	}

	{
		DllPQueue a; a.Enqueue("1");	a.Enqueue("2");	a.Enqueue("3");	a.Enqueue("3");	a.Enqueue("2");	a.Enqueue("1");
		DllPQueue b; b.Enqueue("a");	b.Enqueue("b");	b.Enqueue("c");	b.Enqueue("c");	b.Enqueue("b");	b.Enqueue("a");
		a.Print();
		b.Print();
		DllPQueue* c = a.Merge(&a, &b);
		c->Print();
		c->Deflate(true);
	}

	
}
void TestDllQ()
{
	DllPQueue dllQ;
	dllQ.Enqueue("3");
	dllQ.Enqueue("2");
	dllQ.Enqueue("1");
	dllQ.Enqueue("a");
	dllQ.Enqueue("b");
	dllQ.Enqueue("c");
	dllQ.Enqueue("c");
	dllQ.Enqueue("b");
	dllQ.Enqueue("a");
	std::cout << "printing\n";
	dllQ.Print();
	std::cout << "extracting\n";
	std::cout << dllQ.ExtractMin();
	std::cout << dllQ.ExtractMin() << std::endl;
	std::cout << "printing\n";
	dllQ.Print();
	dllQ.Deflate(true);
}
void TestSpeeds()
{
	FrameTimer ftimer;
	{
		DllPQueue queue;
		//VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("20EnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "DOUBLY LINKED LIST EXECUTION.\n";
		std::cout << "=============================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
			std::cout << "extract: " << queue.ExtractMin() << std::endl;
			std::cout << "extract: " << queue.ExtractMin() << std::endl;
			std::cout << "extract: " << queue.ExtractMin() << std::endl;
			std::cout << "extract: " << queue.ExtractMin() << std::endl;
			std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("20EnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "VECTOR EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		//VectorPQueue queue;
		HeapPQueue queue;
		std::ifstream in("20EnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "BINARY HEAP EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	
	{
		DllPQueue queue;
		//VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("2kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "DOUBLY LINKED LIST EXECUTION.\n";
		std::cout << "=============================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("2kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "VECTOR EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		//VectorPQueue queue;
		HeapPQueue queue;
		std::ifstream in("2kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "BINARY HEAP EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		DllPQueue queue;
		//VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("20kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "DOUBLY LINKED LIST EXECUTION.\n";
		std::cout << "=============================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		VectorPQueue queue;
		//HeapPQueue queue;
		std::ifstream in("20kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "VECTOR EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	{
		//DllPQueue queue;
		//VectorPQueue queue;
		HeapPQueue queue;
		std::ifstream in("20kEnglishWords.txt");

		while (!in.eof())
		{
			std::string str = "";
			for (char ch = in.get(); ch != 10 && !in.eof(); ch = in.get())
			{
				str += ch;
			}
			queue.Enqueue(str);
		}
		std::cout << "BINARY HEAP EXECUTION.\n";
		std::cout << "=================\n";
		std::cout << "Number of words: " << queue.GetLength() << std::endl;
		std::cout << "Enqueue time: " << ftimer.Mark() << std::endl;
		std::cout << std::string(10, '-') << std::endl;
		std::cout << "First five extracts:\n";
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		std::cout << "extract: " << queue.ExtractMin() << std::endl;
		queue.Deflate(false);
		std::cout << "Dequeue time: " << ftimer.Mark() << std::endl << std::endl << std::endl;
	}
	
}

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	//TestVectorPQ();
	//TestInputs(); 
	//TestMerge(); 
	//TestDllQ();
	TestSpeeds();
	
	_CrtDumpMemoryLeaks();

	std::cin.get();
	return 0;
}