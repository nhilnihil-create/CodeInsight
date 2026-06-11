#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll com(ll a,ll b)
{
	ll res = 1;
	for(int i = 1;i<=b;i++)
	{
		res*=a--;
		res/=i;
	}
	return res;
}

int main()
{
	ll n,p;
	cin >> n >> p;
	ll cnt[2] = {};
	ll ans = 0;
	for(int i = 0;i<n;i++)
	{
		int x;
		cin >> x;
		cnt[x%2]++;
	}
	if(p==1)
	{
		for(ll i = 1;i<=cnt[1];i+=2)
		{
			ans+= com(cnt[1],i);
		}
	}
	else
	{
		for(ll i=0;i<=cnt[1];i+=2)
		{
			ans+= com(cnt[1],i);
		}
	}
	ans*=(1LL<<cnt[0]);
	cout<<ans<<endl;
	
}