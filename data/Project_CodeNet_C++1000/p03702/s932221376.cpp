#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 100002
using namespace std;
ll n,a,b;
ll s[maxn];
bool judge(ll mid)
{
    ll ans=mid;
    for(int i=0;i<n;i++)
    {
      ll temp=s[i]-b*mid;
        if(temp>0)
        {
           ll ss=temp/(a-b)+(temp%(a-b)==0 ? 0:1);
            ans-=ss;
            if(ans<0)
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
    }
    ll l=0,r=INF,ans=0;
    while(l<=r)
    {
         ll mid=(l+r)>>1;
         if(judge(mid)) ans=mid,r=mid-1;
         else
            l=mid+1;

    }
     printf("%lld\n",ans);

}
