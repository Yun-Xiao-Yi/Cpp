> 🌹作者:云小逸                                  
> 📝个人主页:[云小逸的主页](https://blog.csdn.net/m0_68865259?spm=1019.2139.3001.5343)          
> 📝Github:[云小逸的Github](https://github.com/NanXing003)                                  
> 🤟motto:要敢于一个人默默的面对自己，**==强大自己才是核心==**。不要等到什么都没有了，才下定决心去做。种一颗树，最好的时间是十年前，其次就是现在！学会自己和解，与过去和解，努力爱自己。==希望春天来之前，我们一起面朝大海，春暖花开！==🤟                                                                
> 👏专栏：C++👏   👏专栏：Java语言👏👏专栏：Linux学习👏                                                 
> 👏专栏：C语言初阶👏👏专栏：数据结构👏👏专栏：备战蓝桥杯👏


@[TOC](文章目录)

---
# 前言
今天我们接着上一篇文章继续学习C++引用（上）继续学习C++引用相关的知识，码字不易，希望多多支持！


![034FA80F.gif](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/c2919e2f77da42e0a53489d4be2186c0~tplv-k3u1fbpfcp-watermark.image?)
——————————————————————————————


---
# 四.传值、传引用效率比较：
## 减少拷贝，提高效率：
以值作为参数或者返回值类型，在传参和返回期间，函数不会直接传递实参或者将变量本身直 接返回，而是传递实参或者返回变量的一份临时的拷贝，因此用值作为参数或者返回值类型，效 率是非常低下的，尤其是当参数或者返回值类型非常大时，效率就更低。
```cpp
#include <time.h>
// 4w byte
struct A{ int a[10000]; };

A a;
// 值返回
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2(){ return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	TestReturnByRefOrValue();

	return 0;
}
```


![Snipaste_2023-04-11_16-58-43.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/71c71bbad07f4e2fbd906778d851b141~tplv-k3u1fbpfcp-watermark.image?)
**通过这段代码我们可以很清楚地看到传值返回和传引用返回的区别；
传引用返回效率高于传值返回。**


## 可以修改返回值：

![Snipaste_2023-04-11_17-24-40.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/dec5eaff070d41ceaeb19b5a8f6d320a~tplv-k3u1fbpfcp-watermark.image?)

**像这段代码中，引用返回，代表临时变量是psl->a[pos]的别名，对其进行*2操作，相当于对psl->a[pos]进行操作。**

## 引用作返回值：


![4.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/206bed5154b84658bd3001183054be3b~tplv-k3u1fbpfcp-watermark.image?)

**就像这段代码：
先建立main函数栈帧，在main函数栈帧中开辟两个空间存入a,b
然后建立Swap1函数栈帧，在Swap1函数栈帧中再次开辟两个空间存入left,right,分别拷贝a,b；
最后建立Swap2函数栈帧，在Swap2函数栈帧中left作a的别名，right作b的别名。**

**从上面可以看出引用的强大：**

![3.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/19d8ce453ab14f58bcfefd27b5188a49~tplv-k3u1fbpfcp-watermark.image?)
### 注：
**如果将Swap1和Swap2命名一样，如swap，那算不算函数重载吗？
构成，但是不会编译通过！！！**

![5.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/03d72d249a3a4bab8023578983c4789c~tplv-k3u1fbpfcp-watermark.image?)

# 五.常引用：

## 1.先看一个例子：

![6.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/9a1c753caf544fd8a8e0069d1387269b~tplv-k3u1fbpfcp-watermark.image?)
```cpp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 0;
	// 权限平移
	int& ra = a;

	// 指针和引用赋值中，权限可以缩小，但是不能放大
	const int b = 1;//只读

	// 我引用你，权限放大 不行
	//int& rb = b;//只读---->>>>>可读可写，权限放大
	
	const int& rra = a;
		a++;
	
	cout << rra << endl;

	// 权限平移
	const int& rb = b;

	return 0;
}
```
**从上面可以知道：指针和引用赋值中，权限可以缩小，但是不能放大**


![7.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/3645399ca11146adb21b9296078d15fd~tplv-k3u1fbpfcp-watermark.image?)

```cpp

void TestConstRef()
{
	const int a = 10;
	//int& ra = a;   // 该语句编译时会出错，a为常量
	const int& ra = a;
	// int& b = 10; // 该语句编译时会出错，b为常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d;
}
```
## 2.void func(const int& N = 10)
**这里为什么是const ？？？<br>
请看：**

![8.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/807cc25aa33f49ada04282a86fd66ff3~tplv-k3u1fbpfcp-watermark.image?)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 减少拷贝,提高效率、
// 一般用引用做参数都是用const 引用
void Func(int& x)
{

}

int main()
{
	int a = 0;
	// 权限平移
	int& ra = a;

	// 指针和引用赋值中，权限可以缩小，但是不能放大
	const int b = 1;//只读

	// 我引用你，权限放大 不行
	//int& rb = b;//只读---->>>>>可读可写，权限放大
	
	const int& rra = a;
		a++;
	
	cout << rra << endl;

	// 权限平移
	const int& rb = b;

	Func(a);
	Func(b);
	Func(rra);
	Func(10);

	return 0;
}

```

**当函数参数用int& x（可读可写）的时候，b（只可读），raa（只可读），10（只可读）
由于在指针和引用中权限只可以缩小，不可以放大。因此传参出现错误，
如果想正确需要将其改为：
void Func(const int& x)**

![9.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/597f2a1476964822b01408cd06098d13~tplv-k3u1fbpfcp-watermark.image?)

**所以就像我们C++很多接口使用const int& a原因就在此：**

![10.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/69894aa174164eaa8270b29c12981607~tplv-k3u1fbpfcp-watermark.image?)
**这样就可以出现实参（可以是常量）到形参权限是放大而报错！！！**
## 3.引用和缺省参数：
### void func(int& N = 10)错误

![11.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/3aeaa27eea0a4b5a935060e7ce9e2472~tplv-k3u1fbpfcp-watermark.image?)
改为：
**void func(const int& N = 10)**

![12.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/8bdd40f037184ac19d1d8c4ec3d52207~tplv-k3u1fbpfcp-watermark.image?)
### int& ri = d;
#### int i = (int)d; // 可以,类型转换（强制），转换过程中会产生一个临时变量

![14.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/5eaadee7991e4ed6833eadc03a1ba430~tplv-k3u1fbpfcp-watermark.image?)


```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void func(const int& N = 10)
{

}

int Count()
{
	int n = 0;
	n++;
	// ...
	return n;
}

int main()
{
	const int& b = 10;

	double d = 12.34;

	cout << (int)d << endl;

	int i = (int)d; // 可以,类型转换（强制），转换过程中会产生一个临时变量

	return 0;
}
```
int i = (int)d; // 类型转换（强制），转换过程中会产生一个临时变量,而不是将d转换为整形

![15.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/7c390bf65c074be489c45746ff02aff1~tplv-k3u1fbpfcp-watermark.image?)

cout << (int)d << endl;打印的不是d，而是临时变量，临时变量具有常性！！！


![17.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/3133f7eca09c4873852e91d1cf308838~tplv-k3u1fbpfcp-watermark.image?)

**所以用：<br>
const int& ri=d;**
## 4.传值返回+引用

![19.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/a9991c9beff548f28fd5357f726fb10a~tplv-k3u1fbpfcp-watermark.image?)


```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void func(const int& N = 10)
{

}

int Count()
{
	int n = 0;
	n++;
	// ...
	return n;
}

int main()
{
	const int& b = 10;

	double d = 12.34;

	cout << (int)d << endl;

	int i = (int)d; // 可以,类型转换（强制），转换过程中会产生一个临时变量

	//int& ri = d; // 不可以

	//const int& ri = d; // 可以
	//cout << ri << endl;

	int& ret = Count();
	//const int& ret = Count();

	return 0;
}
```
**在这里return n返回一个临时变量，临时变量是常性，int& ret=Count();就会出现权限放大，出现错误，编译不会通过。**

# 六.引用和指针的区别
## 语法概念：
**在语法概念上引用就是一个别名，没有独立空间，和其引用实体共用同一块空间。**

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int& ra = a;
	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;
	return 0;
}
```

![20.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/e3f457841a8c494baa15c39ba3335cba~tplv-k3u1fbpfcp-watermark.image?)
## 底层概念：
**在底层实现上实际是有空间的，因为引用是按照指针方式来实现的。**

![21.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/db17efd65ff044c3bb24c7dc8c593cd5~tplv-k3u1fbpfcp-watermark.image?)
可以从上图看到两者代码的反汇编其实是一样的！！！

![22.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/7f8e466366b4472f8ca33faa9ccba51a~tplv-k3u1fbpfcp-watermark.image?)
## 总结：
> 引用和指针的不同点: 
> 1. 引用概念上定义一个变量的别名，指针存储一个变量地址。 
> 2. 引用在定义时必须初始化，指针没有要求 
> 3. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何 一个同类型实体 
> 4. 没有NULL引用，但有NULL指针 
> 5. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32 位平台下占4个字节) 
> 6. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小 
> 7. 有多级指针，但是没有多级引用 
> 8. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理 9. 引用比指针使用起来相对更安全


---

# 最后
 **十分感谢你可以耐着性子把它读完和我可以坚持写到这里，送几句话，对你，也对我：**

<font color="#006600">1.跟蠢人交流你会有一个很明显的感觉：**你说的每一句话，他都想要反驳。**</font><br />

<font color="#666600">2.性是肉体生活，遵循快乐原则

爱情是精神生活，遵循理想原则；

婚姻是社会生活，遵循现实原则。是三个完全不同的东西。

*——[周国平]《婚姻与爱情》*</font><br /> 

<font color="#006666">3.**没有钱，没有社会地位，没有文化，人很难掌握自己的命运。**

*——《沉默的大多数》*</font><br /> 


<font color="#D2691E">4.人性最大的丑陋就是：

**在无权无势的人身上挑毛病，在有权有势的人身上找优点。**</font><br />

<font color="#32CD32">5.如果一个人影响到你的情绪，你的焦点应该放到控制自己情绪上，而不是影响你的那个人上。

*——马克吐温*
</font><br /> 


---
**最后如果觉得我写的还不错，请不要忘记==点赞==✌，==收藏==✌，加==关注==✌哦(｡･ω･｡)**

**愿我们一起加油，奔向更美好的未来，愿我们从懵懵懂懂的一枚==菜鸟==逐渐成为==大佬==。加油，为自己点赞！**



---