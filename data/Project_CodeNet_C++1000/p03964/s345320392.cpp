#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
ll ceil1(ll a,ll b)
{
	if(a%b==0)
		return a/b;
	else
		return a/b+1;
}

void solve()
{
	ll n,a,b;
	cin>>n;
	a=1,b=1;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		ll temp=max(ceil1(a,x),ceil1(b,y));
		a=temp*x;
		b=temp*y;
	}
	cout<<a+b;
	
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

