#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=200005;
long long tree[N];
long long ans;
long long n,k;
struct node
{
    long long tot,id;
}sum[N];
long long lowbit(long long x)
{
    return x&(-x);
}
void modify(long long x)
{
    if (x==0)
    {
      tree[x]++;
      return;
    }
    while (x<=n)
    {
        tree[x]++;
        x+=lowbit(x);
    }
}
long long add(long long x)
{
    long long sum1=tree[0];
    while (x>0)
    {
        sum1+=tree[x];
        x-=lowbit(x);
    }
    return sum1;
}
bool cmp(node a,node b)
{
    if (a.tot==b.tot)
        return a.id < b.id;
    return a.tot < b.tot;
}
int main()
{
    scanf("%lld%lld",&n,&k); 
    sum[0].id=0;
    sum[0].tot=0;
    for (long long i=1;i<=n;i++)
    {
        long long x;
        scanf("%lld",&x);
        sum[i].tot=sum[i-1].tot+x-k;
        sum[i].id=i;
    }
   
    sort(sum,sum+1+n,cmp);
    ans = 0;
    for (long long i=0;i<=n;i++)
    {
       if (sum[i].id>0) ans+=add(sum[i].id-1);
       modify(sum[i].id);

    }
    printf("%lld\n",ans);
    return 0;
}