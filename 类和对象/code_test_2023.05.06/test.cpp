#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
//private:
	char _a;
	int _b;
};

class A2 {
public:
	void f2() {}
};

class A3
{};
int main()
{
	A aa1;
	A aa2;
	//A aa3;
	cout << sizeof(aa1) << endl;

	// 1 ���洢��Ч���ݣ�ռλ����ʶ�������
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	A2 aaa2;
	A2 aaaa2;
	cout << &aaa2 << endl;
	cout << &aaaa2 << endl;

	aa1._a = 'A';
	aa1.PrintA();

	aa2._a = 'a';
	aa2.PrintA();


	return 0;
}
