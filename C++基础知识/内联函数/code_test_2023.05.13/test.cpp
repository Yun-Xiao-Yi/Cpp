#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//#define ADD(int x, int y) {return x + y;}
//#define ADD(x, y) x + y
//#define ADD(x, y) (x + y)
//#define ADD(x, y) (x) + (y)
//#define ADD(x, y) ((x) + (y));

//#define ADD(x, y) ((x) + (y))

inline int add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 1, b = 2;
	int c = add(a, b);
	cout << c << endl;
	return 0;
}