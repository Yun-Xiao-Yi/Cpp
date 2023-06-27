#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    auto a = &x;
    auto* b = &x;
    auto& c = x;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    *a = 20;
    *b = 30;
    c = 40;
    return 0;
}