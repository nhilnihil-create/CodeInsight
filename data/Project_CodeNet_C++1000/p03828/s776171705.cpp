#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pair<ll,ll>>PF(ll n)
{
	vector<pair<ll,ll>>v;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll cnt=0;
			while(n%i==0)
			{
				n/=i;
				cnt++;
			}
			v.push_back(make_pair(i,cnt));
		}
	}
	if(n!=1)v.push_back(make_pair(n,1));
	return v;
}


int main()
{
	ll n,t[1005]={},MOD=1000000007,ans=1;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		vector<pair<ll,ll>>w=PF(i);
		for(ll j=0;j<w.size();j++)
		{
			t[w[j].first]+=w[j].second;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(t[i])ans=ans*(t[i]+1)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}