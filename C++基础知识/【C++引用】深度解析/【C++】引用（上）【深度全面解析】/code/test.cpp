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
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
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
//// 减少拷贝,提高效率、
//// 一般用引用做参数都是用const 引用
//void Func(const int& x)
//{
//
//}
//
//int main()
//{
//	int a = 0;
//	// 权限平移
//	int& ra = a;
//
//	// 指针和引用赋值中，权限可以缩小，但是不能放大
//	const int b = 1;//只读
//
//	// 我引用你，权限放大 不行
//	//int& rb = b;//只读---->>>>>可读可写，权限放大
//	
//	const int& rra = a;
//		a++;
//	
//	cout << rra << endl;
//
//	// 权限平移
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

 /*语法上面，ra是a的别名，不开空间
 底层实现，引用是使用指针实现的*/
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
//	int i = (int)d; // 可以,类型转换（强制），转换过程中会产生一个临时变量
//
//	//int& ri = d; // 不可以
//
//	//const int& ri = d; // 可以
//	//cout << ri << endl;
//
//	int& ret = Count();
//	//const int& ret = Count();
//
//	return 0;
//}