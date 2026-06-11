#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[100009];
struct ss
{
    ll v;
    ll pos;
}a[100009];
const bool com(const ss &a,const ss&b)
{
    if(a.v>b.v)return 1;
    else if(a.v==b.v)
    {
        return a.pos<b.pos;
    }
    return 0;
}
 int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].v);
        a[i].pos=i;
    }
    sort(a+1,a+1+n,com);
    /*for(ll i=1;i<=n;i++)
    {
        cout<<a[i].v<<" "<<a[i].pos<<endl;
    }*/
    a[n+1].v=0;
    ll tmp=1;
    ll num=a[1].pos;
    for(ll i=2;i<=n+1;i++)
    {
        if(a[i].v==a[i-1].v)tmp++;
        else
        {
            ans[num]+=(a[i-1].v-a[i].v)*tmp;
            tmp++;
        }
        if(a[i].pos<num)
        {
            num=a[i].pos;
        }
    }
    for(ll i=1;i<=n;i++)
    {
       printf("%lld\n",ans[i]);
    }
}
