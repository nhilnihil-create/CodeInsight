#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>> a(m);
	vector<ll> v,k;
	for(ll i=0;i<m;i++)
	{
		cin>>a[i].first>>a[i].second;
		if(a[i].first==1)
			v.push_back(a[i].second);
		if(a[i].second==1)
			v.push_back(a[i].first);
		if(a[i].first==n)
			k.push_back(a[i].second);
		if(a[i].second==n)
			k.push_back(a[i].first);
	}
	if(m==1)
	{
		cout<<"IMPOSSIBLE";
		return;
	}
	map<ll,ll> mp;
	for(ll i=0;i<v.size();i++)
	{
		mp[v[i]]++;
	}
	for(ll i=0;i<k.size();i++)
	{
		if(mp[k[i]]>0)
		{
			if(k[i]!=1)
			{
				cout<<"POSSIBLE";
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE";
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