#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int& count()
{
	int n = 0;
	n++;
	return n;
}

int main()
{
	int& ret = count();

	cout << ret << endl;
	cout << ret << endl;
	cout << ret << endl;

	return 0;
}