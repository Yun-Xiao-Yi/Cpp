//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//int& count()
//{
//	int n = 0;
//	n++;
//	cout << &n << endl;
//	return n;
//}
//
//void Func()
//{
//	int x = 100;
//	cout << &x << endl;
//}
//
//int main()
//{
//	int& ret = count();
//
//	cout << ret << endl;
//	cout << ret << endl;
//	Func();
//	cout << ret << endl;
//	cout << &ret << endl;
//	return 0;
//}
//
//#include <time.h>
//// 4w byte
//struct A{ int a[10000]; };
//
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}
//
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(int left, int right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	Swap(a, b);
//
//	return 0;
//}



//
//// ���ٿ���,���Ч�ʡ�
//// һ��������������������const ����
//void Func(const int& x)
//{
//
//}
//
//int main()
//{
//	int a = 0;
//	// Ȩ��ƽ��
//	int& ra = a;
//
//	// ָ������ø�ֵ�У�Ȩ�޿�����С�����ǲ��ܷŴ�
//	const int b = 1;//ֻ��
//
//	// �������㣬Ȩ�޷Ŵ� ����
//	//int& rb = b;//ֻ��---->>>>>�ɶ���д��Ȩ�޷Ŵ�
//	
//	const int& rra = a;
//		a++;
//	
//	cout << rra << endl;
//
//	// Ȩ��ƽ��
//	const int& rb = b;
//
//	Func(a);
//	Func(b);
//	Func(rra);
//	Func(10);
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

 /*�﷨���棬ra��a�ı����������ռ�
 �ײ�ʵ�֣�������ʹ��ָ��ʵ�ֵ�*/
int main()
{
	int a = 10;

	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 30;

	return 0;
}
















//
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	return 0;
//}
//














//
//void func(const int& N = 10)
//{
//
//}
//
//int Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	const int& b = 10;
//
//	double d = 12.34;
//
//	cout << (int)d << endl;
//
//	int i = (int)d; // ����,����ת����ǿ�ƣ���ת�������л����һ����ʱ����
//
//	//int& ri = d; // ������
//
//	//const int& ri = d; // ����
//	//cout << ri << endl;
//
//	int& ret = Count();
//	//const int& ret = Count();
//
//	return 0;
//}