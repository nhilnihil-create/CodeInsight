#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x=min(max(a,b),d);
	ll y=max(min(c,d),a);
	if(x-y>0)
		cout<<x-y;
	else
		cout<<0;
		
	return;
}


int main()
{
	fast;
	ll q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
