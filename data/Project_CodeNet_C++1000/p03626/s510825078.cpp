#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	ll n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	ll ans=1;
	ll i=1;
	if(s1[0]==s2[0])
	{
		ans*=3;
	}
	else
	{
		ans*=6;
		i++;
	}
	for(;i<n;i++)
	{
		if(s1[i]==s2[i])
		{
			if(s1[i-1]!=s2[i-1])
				ans*=1,ans%=mod;
			else
				ans*=2,ans%=mod;
		}
		else
		{
			if(s1[i-1]!=s2[i-1])
				ans*=3,ans%=mod;
			else
				ans*=2,ans%=mod;
			i++;
		}
	}
	cout<<ans;
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
