#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll n,x;
	cin>>n>>x;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll ans=0;
	for(ll i=1;i<n;i++)
	{
		if(a[i]+a[i-1]>x)
		{
			ll c=a[i]+a[i-1]-x;
			ll t=c;
			if(a[i]>=c)
				a[i]-=c;
			else
			{
				c-=a[i];
				a[i]=0;
				a[i-1]-=c;
			}
			ans+=t;
		}
	}	
	cout<<ans;
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

