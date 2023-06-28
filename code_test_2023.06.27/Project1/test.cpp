#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N];

void quick_sort(int a[N], int l, int r)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1;
    int x = a[(l + r) / 2];
    while (i < j)
    {
        do i++;
        while (a[i] < x);
        do j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }

    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    int k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quick_sort(a, 0, n - 1);

    cout << a[k-1];//ÕâÀï

    return 0;
}