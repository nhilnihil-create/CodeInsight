#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n ;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    int p;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=i)
            p=i;
        else break;
    }
    int q;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=p)
            q=i;
    }
    if(((a[p]-p+1)&1)&&((q-p+1)&1))
    {
        printf("Second");
    }
    else puts("First");

}
