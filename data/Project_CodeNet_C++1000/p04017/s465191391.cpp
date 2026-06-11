#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009];
ll d[30][100009];
ll n,l,q;
void init()
{
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            d[i][j]=d[i-1][d[i-1][j]];
        }
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    scanf("%lld%lld",&l,&q);
    for(ll i=1; i<=n; i++)
    {
        ll z=i+1;
        ll y=n;
        while(z<=y)
        {
            ll mid=(z+y)/2;
            if(a[mid]-a[i]<=l)
            {
                z=mid+1;
            }
            else
            {
                y=mid-1;
            }
        }
        d[0][i]=z-1;
    }
    init();

   ll a,b;
   for(ll k=1;k<=q;k++)
   {
       ll tot=0;
       scanf("%lld%lld",&a,&b);
       if(a>b)
       {
           swap(a,b);
       }
       for(ll i=20;i>=0;i--)
       {
           if(d[i][a]<b)
           {
               tot+=(1ll<<i);
               a=d[i][a];
           }
       }
       tot++;
       cout<<tot<<endl;
   }

}
