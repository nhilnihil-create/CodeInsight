#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define maxn 100005
using namespace std;
ll sum[maxn];
int n;
struct node
{
    int id;
    ll val;
}a[maxn];
bool cmp(node a,node b)
{
    if(a.val==b.val)
return a.id<b.id;
return a.val>b.val;
}
int main()
{
 
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        {scanf("%lld",&a[i].val);
        a[i].id=i;
        }
    sort(a+1,a+n+1,cmp);
    int pos=a[1].id;
   ll num=1;
    a[n+1].val=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i+1].val==a[i].val)
            num++;
            else
            {
              sum[pos]+=(a[i].val-a[i+1].val)*num;
              num++;
             if(a[i+1].id<pos)
                pos=a[i+1].id;
            }
 
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",sum[i]);
    return 0;
 
 
}