#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5;
using namespace std;
int n,a[N + 5],mx,a1;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    sort(a + 1,a + n + 1,cmp);
    for (int i = 1;i <= n;i++)
        if (i <= a[i])
            mx = i;
    for (int i = mx + 1;i <= n;i++)
        if (mx <= a[i])
            a1 = i - mx;
    if (a1 % 2 == 1 || (a[mx] - mx) % 2 == 1)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}