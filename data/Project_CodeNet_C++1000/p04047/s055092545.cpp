#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,n) for(i=a;i<n;i++)
#define in(x) scanf("%lld",&x)
void solve()
{
    ll n,i;
    in(n);
    ll a[2*n];
    f(i,0,2*n)
    in(a[i]);
    sort(a,a+2*n);
    ll ans=0;
    for(i=0;i<2*n;i+=2)
        ans+=a[i];
    printf("%lld\n",ans);
}
int main()
{
    ll t;
	// cin>>t;
	// while(t--)
		solve();
}