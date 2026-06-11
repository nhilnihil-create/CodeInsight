#include <iostream>
#include <bits/stdc++.h>

const int MAXN=1e5+5;
const int INF=0x3f3f3f3f;

using namespace std;

int a[MAXN];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    int t=0;
    sort(a+1,a+n+1,cmp);
    for(; a[t]>=t; t++);
    t--;
    int flag=0;
    if((a[t]-t)%2==0)
    {
        int j;
        for( j=0; a[j+t]>=t; j++);
        if((j-1)%2==0)
        {
            flag=1;
        }
    }
    printf(!flag?"First\n":"Second\n");
    return 0;
}
