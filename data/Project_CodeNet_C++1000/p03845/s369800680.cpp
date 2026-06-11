#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
		cin>>a[i],sum+=a[i];
	ll m;
	cin>>m;
	while(m--)
	{
		ll p,x;
		cin>>p>>x;
		p--;
		cout<<sum-a[p]+x<<endl;;
	}
	return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}