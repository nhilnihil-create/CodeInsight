#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,n) for(i=a;i<n;i++)
#define in(x) scanf("%lld",&x)
ll fun(ll a,ll b)
{
    if(a==b)
    return a;
        ll u=(b-a)/a;
        ll k=2*a*u;
        if(b-u*a==a)
            return a+k;
        return k+2*a+fun(b-(u+1)*a,a);
}
void solve()
{ 
    ll n,x;
    cin>>n>>x;
    ll a,b;
    a=x;
    b=n-x;
    if(a>b)
        swap(a,b);
    ll ans=n+fun(a,b);
    cout<<ans;
}
int main()
{
  //   ll t;
	 // cin>>t;
	 // while(t--)
		solve();
}