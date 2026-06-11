#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool isok(P a,P b,ll c)
{
	ll a1 = a.first;
	ll a2 = a.second;
	ll b1 = b.first;
	ll b2 = b.second;
	ll cc = (b1+a1-1)/a1;
	ll cc1 = (b2+a2-1)/a2;
	if(cc>c||cc1>c)
		return 0;
	return 1;
}
int main()
{
	ll n;
	cin>>n;
	vector<P> vi;
	for(ll i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		vi.push_back(P(a,b));
	}
	for(ll i=1;i<n;i++)
	{
		if(vi[i].first<vi[i-1].first||vi[i].second<vi[i-1].second)
		{
			ll ri = max(vi[i-1].first,vi[i-1].second);
			ll le = 1;
			ll mid;
			while(le+1<ri)
			{
				mid = (ri+le)/2;
				if(!isok(vi[i],vi[i-1],mid))
					le = mid;
				else
					ri = mid;
			}
			vi[i].first*=ri;
			vi[i].second*=ri;
		}
	}
	cout<<vi[n-1].first+vi[n-1].second<<endl;
	return 0;
}