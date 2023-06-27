> 🌹作者:云小逸                                  
> 📝个人主页:[云小逸的主页](https://blog.csdn.net/m0_68865259?spm=1019.2139.3001.5343)          
> 📝Github:[云小逸的Github](https://github.com/NanXing003)                                  
> 🤟motto:要敢于一个人默默的面对自己，**==强大自己才是核心==**。不要等到什么都没有了，才下定决心去做。种一颗树，最好的时间是十年前，其次就是现在！学会自己和解，与过去和解，努力爱自己。==希望春天来之前，我们一起面朝大海，春暖花开！==🤟                                                                
> 👏专栏：C++👏   👏专栏：Java语言👏👏专栏：Linux学习👏                                                 
> 👏专栏：C语言初阶👏👏专栏：数据结构👏👏专栏：备战蓝桥杯👏


@[TOC](文章目录)

---
# 前言
今天我们来学习C++很重要的知识点：【引用】，这里会详细讲解到C++引用的各种知识，码字不易，请多多支持![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/f3a29a5dbc3743049f2e4e6fe406b723~tplv-k3u1fbpfcp-zoom-1.image)

——————————————————————————————


---
# 概念：
**引用不是新定义一个变量，而是给已存在变量==取了一个别名==，*编译器不会为引用变量开辟内存空
间，它和它引用的变量共用同一块内存空间*。**
即：
1. 取别名
2. 不会开辟新空间，只是与所引用的共用一块空间

我们可以看下面的截图，便于我们的理解：
不难看出创建指针pa是开辟一个新空间存放a的地址。
ra的地址和a的地址是一样的
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/e6f95dad17414aa5b1b4c2802e97dffc~tplv-k3u1fbpfcp-zoom-1.image)
因为C++中出现了引用，很多我们之前写的代码就可以优化一下了,比如：
Swap函数：
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/64f546c3a4a84c3080ceaca0129fed27~tplv-k3u1fbpfcp-zoom-1.image)




## 格式：
**类型& 引用变量名(对象名) = 引用实体；**
***注意：引用类型必须和引用实体是同种类型的***

# 特性：
## 1. 引用在定义时必须初始化
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/8a843812c11d4633a6027a9d9c9ea653~tplv-k3u1fbpfcp-zoom-1.image)




## 2. 一个变量可以有多个引用

![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/cd1f4acd110e49aca06f7515ea2f1c40~tplv-k3u1fbpfcp-zoom-1.image)


## 3. 引用一旦引用一个实体，再不能引用其他实体
先举一个例子，便于后面的理解：

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int& ra = a;
	int b = 20;

	ra = b;

	return 0;
}
```

可以思考一下：ra=b是将ra的引用的指向还是将b的值赋值给ra？
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/8647a4f1e5cb45adb3f3ccb61834ca83~tplv-k3u1fbpfcp-zoom-1.image)

发现了吗？
是直接赋值的，而不是改变ra的引用的指向。
从这里我们也可以看到，赋值给ra，a的值也随之改变。
**注：这个只是在C++中是这样的，Python等语言中引用的指向是可以改变的（可以替代指针），因此C++中引用不可以完全取代指针。**


# 使用场景：
## 1.做参数：（和指针重合的功能）
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/e091aa11519148479722b02011ff0caf~tplv-k3u1fbpfcp-zoom-1.image)

![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/8b9879aa9b6f4ee6b35f0c1026c75878~tplv-k3u1fbpfcp-zoom-1.image)



还有可能我们刚开始学习数据结构的时候，经常看到书上是这样的写的：
void SListPushBack(Node*& pphead,int x);
那时候没有学习C++的引用的话，那就比较迷，那时候我也是这样的☹
现在学完C++的引用就会知道这是对Node*的引用
## 2.做返回值：
下面举几个例子用于对比，理解：
### 1. int cout()--------static int n=0;
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/374523135f2c4707bd308f7d5c081651~tplv-k3u1fbpfcp-zoom-1.image)
* 这个函数是**先建立main函数的栈帧，在main函数的栈帧开辟一块空间将ret存入,然后再建立count函数的栈帧**，那我们创建的静态变量在不在count栈帧中呢？
* **不在的**，这里涉及了操作系统的内容，未来在操作系统那一专栏将会系统介绍这个，这里先讲个大概：**有一个叫作进程地址空间，里面分为几大区域，有栈（有栈帧，先建立的函数在上面，后建立的函数在上面），对，静态区（操作系统中叫数据段），常量区（操作系统中叫代码段）**。
* 因此栈帧销毁了， **n没有受到影响。
static定义的变量放在静态区中，运行完count函数，n也不会被销毁。**

#### 注：
* **传值返回的本质不是把n作为函数调用的返回值，而是中间产生一个临时变量**（**小的话放在寄存器，单个寄存器只有4个字节或者8个字节，大的话放在上一层栈帧某个位置**），临时变量的类型是int，与函数返回值的类型对应,然后n赋值给临时变量，临时变量作为函数调用的返回值。
为什么呢？
* 这里要考虑n是局部变量的时候的情况：下一个例子为你解答：
### 2. int cout()--------int n=0;
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/215a023f81834ec69462dd02918d7909~tplv-k3u1fbpfcp-zoom-1.image)
**上面传值返回的本质之所以是那样的是因为函数调用完，如果n不是静态变量，而是局部变量的话，当函数调用完成的时候，直接返回n的话，此时n已经被销毁了，返回的值是随机值。【此时销毁的空间还在，但是使用权不属于你，发生越界返回】**


### 3. int& count()-------static int n=0;

![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/260ad636ea83432cb31f13c0a8246ecd~tplv-k3u1fbpfcp-zoom-1.image)


**如果引用返回，也会产生临时变量，此时临时变量是n（静态变量）的别名。
n不在count栈帧中。**
### 4. int& count()-------int n=0;//这个程序是不对的！！！

![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/5bde5882d3ec432c877420b7d30e8843~tplv-k3u1fbpfcp-zoom-1.image)
如果引用返回，也会产生临时变量，此时临时变量是n（局部变量）的别名，此时就会出现问题，n已经被销毁，函数调用返回临时变量，相当于访问野指针。
##### 内存销毁意味着什么？
![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/398cdd9cce9c4bbb8090c7d491b8b90c~tplv-k3u1fbpfcp-zoom-1.image)
空间销毁后，访问这个空间存在多种情况：
1. 还可以正常使用。
2. 被新数据覆盖了。
3. 还有一种情况是访问已被销毁的空间会出现未定义行为。这是因为当内存被释放时，系统不会立即清除该内存中的数据，因此如果访问已被销毁的空间，可能会读取到旧的数据或者无效数据，导致程序出现未定义行为。这种情况非常危险，可能会导致程序崩溃、数据损坏或者安全漏洞。因此，在程序中应该避免访问已经被销毁的空间，以确保程序的正确性和安全性。

就如何我们住酒店一样：
我们退房之后再偷偷潜入房间，拿我们落下的物品会出现多种情况：
1. 物品未被人触碰或移动，我们可以顺利取回。

2. 物品被人触碰或移动，我们可能会发现物品的位置或状态发生了变化。

3. 物品被其他人取走或替换，我们可能会发现物品不在原来的位置或者被其他物品所替代。
#### 代码演示：
##### 引用传值：
**这里访问的是已经被销毁的空间，即访问一个野指针，但由于可能该空间没有被再次使用，所以数据暂时还可以使用，但是极度不安全！！！**

```cpp
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
	int ret = count();

	cout << ret << endl;

	return 0;
}
```

![在这里插入图片描述](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/e6df07fab8a54f9fb714050de0c49081~tplv-k3u1fbpfcp-zoom-1.image)

##### 深化理解：

**这里ret是临时变量的别名，临时变量是n的别名，可以这样说：ret是n的别名，但由于n是在count函数栈帧中的，其数据已经被销毁，故会生成随机值**
```cpp
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
```


![3.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/c2305fc0dd8448d38810412592cb28a8~tplv-k3u1fbpfcp-watermark.image?)
**栈是向下生长的，上面高地址，下面低地址**

这里可以继续类比我上面的例子：
1. 我偷偷潜入房间中，发现物品保持原状//1
2. 我偷偷潜入房间中，发现物品被扔在了垃圾堆里//随机值

##### 再深化理解
这里可以发现这里三个地址是一样的：
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int& count()
{
	int n = 0;
	n++;
	cout << &n << endl;
	return n;
}

void Func()
{
	int x = 100;
	cout << &x << endl;
}

int main()
{
	int& ret = count();

	cout << ret << endl;
	cout << ret << endl;
	Func();
	cout << ret << endl;
	cout << &ret << endl;
	return 0;
}
```



![4.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/c8f0abf1a49045babd0397c6a49f3950~tplv-k3u1fbpfcp-watermark.image?)




### 总结：

![5.png](https://p9-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/2ca439ac8cb04a50ac3d422bb0aae330~tplv-k3u1fbpfcp-watermark.image?)

### 正确玩法：

![6.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/f5ce35d11577407cbe1d01f3781bd507~tplv-k3u1fbpfcp-watermark.image?)





---

# 最后
 **十分感谢你可以耐着性子把它读完和我可以坚持写到这里，送几句话，对你，也对我：**

<font color="#006600">1.永远都要保持善良，即便善良的人往往容易受伤，但善良是作为人来说，最宝贵的品质。</font><br />

<font color="#666600">2.二十出头或者十多岁的小男孩们请千万要好好读书，人的一生就只有一次，学生阶段是人生最宝贵的时候，拼命读书才是正事。</font><br /> 

<font color="#006666">3.累了的时候就多睡觉，多跑步，多运动。适当的放松，养好精神后再继续努力方可再创辉煌。</font><br /> 


<font color="#D2691E">4.良人难遇，也要保持初心，相信才会有希望。</font><br />

<font color="#32CD32">5.多独处，多复盘，想想今天自个干了啥，啥没干好，为啥没干好，该怎么干好。
</font><br /> 


---
**最后如果觉得我写的还不错，请不要忘记==点赞==✌，==收藏==✌，加==关注==✌哦(｡･ω･｡)**

**愿我们一起加油，奔向更美好的未来，愿我们从懵懵懂懂的一枚==菜鸟==逐渐成为==大佬==。加油，为自己点赞！**



---