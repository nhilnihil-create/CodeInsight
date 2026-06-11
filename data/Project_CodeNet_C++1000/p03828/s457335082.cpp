#include<bits/stdc++.h>
#define m_p make_pair
#define itll map<ll,ll>::iterator
using namespace std;
typedef long long ll;
ll isp[1000010];
vector<ll> primes;
const ll mod = 1000000007;
int main()
{
	ll n;
	cin>>n;
	map<ll,ll> mp;
	isp[0] = isp[1] = 1;
	for(ll i = 2;i<=n;i++)
	{
		if(!isp[i])
			primes.push_back(i);
		for(ll j = i*i;j<=n;j+=i)
			isp[j] = 1;
	}
	if(n == 1)
	{
		cout<<"1\n";
		return 0;
	}
	ll all = 1;
	for(ll i = n;i>=2;i--)
	{
		ll tmp = i;
		for(int j=0;j<primes.size();j++)
		{
			ll cnt = 0;
			while(tmp%primes[j] == 0)
			{
				tmp/=primes[j];
				cnt++;
			}
			mp[primes[j]]+=cnt;
		}
	}
	for(itll it = mp.begin();it!=mp.end();it++)
	{
		all*=(it->second+1);
		all%=mod;
	}
	cout<<all<<endl;
	return 0;
}