#include <iostream>
using namespace std;
template <typename T>
void myswap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}
template <typename T>
class Stack
{
public:
	Stack(int size)
	{
		space = new T[size];
		topn = 0;
	}
	~Stack()
	{
		delete[] space;
	}
	T pop()
	{
		return space[top--];
	}
	T top()
	{
		return space[topn - 1];
	}
	void push(T a)
	{
		space[topn++] = a;
	}
	bool isempty()
	{
		return topn == 1024;
	}
	T* space;
	int topn;
};
int main()
{
	int a = 0;
	int b = 1;
	myswap(a, b);
}