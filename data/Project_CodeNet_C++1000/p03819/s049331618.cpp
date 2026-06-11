#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300005
#define ll long long
using namespace std;
int c[maxn];
int n,m;
struct node
{
    int l,r;
}a[maxn];
bool cmp(node a,node b)
{
    return a.r-a.l<b.r-b.l;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=m+1)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int res=0;
    while(i>0)
    {
        res+=c[i];
        i-=lowbit(i);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+n+1,cmp);
    int p=1;

    for(int i=1;i<=m;i++)
    {
        while(a[p].r-a[p].l+1<i&&p<=n)
        {  add(a[p].l+1,1);
            add(a[p].r+2,-1);

            p++;
        }

    ll ans=n-p+1;
    for(int j=0;j<=m;j+=i)
    {ans+=sum(j+1);

}
printf("%lld\n",ans);
    }
return 0;
    }
