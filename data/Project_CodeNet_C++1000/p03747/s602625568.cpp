#include<bits/stdc++.h>
#define N 1000010
using namespace std;
struct data
{
    int x,w;
}a[N];
bool cmp(data a,data b)
{
    return a.x<b.x;
}
int n,l,t,sum;
int main()
{
    scanf("%d%d%d",&n,&l,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].w);
        a[i].w--;
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i].w)
        {
            a[i].x+=t;
        }else{
            a[i].x-=t;
        }
        sum+=a[i].x/l;
        if(a[i].x%l<0)
        {
            sum--;
        }
        a[i].x=(a[i].x%l+l)%l;
    }
    sort(a+1,a+n+1,cmp);
    sum=(sum%n+n)%n;
    for(int i=sum+1;i<=n;i++)
    {
        printf("%d\n",a[i].x);
    }
    for(int i=1;i<=sum;i++)
    {
        printf("%d\n",a[i].x);
    }
    return 0;
}