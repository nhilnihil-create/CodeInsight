#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	vector<int> v(101,0);
	for(ll i=2;i<101;i*=2)
	{
		v[i]=1;
	}
	ll n;
	cin>>n;
	for(ll i=n;i>=2;i--)
	{
		if(v[i]==1)
		{
			cout<<i;
			return;
		}
	}
	cout<<1;
	return;
}
int main()
{
	fast;
	int q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}