#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,index,ans=1,cnt0=0;
	cin>>n;
	ll arr[n],pos[n],diff[n]{};
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i],pos[i]=1;
		if(arr[i]==0)
			cnt0++;
		diff[arr[i]]++;
	}
	if(cnt0>1)
	{
		cout<<0;
		return 0;
	}
	for(ll i=0;i<n;i++)
		if(diff[i]>2)
		{
			cout<<0;
			return 0;
		}
	for(ll i=0;i<n;i++)
	{
		index=(n-arr[i])/2;
		// cout<<index<<endl;
		if(arr[i]!=0)
			pos[index]=2;
		else
			pos[index]=1;
	}
	if(n%2)
	{
		for(ll i=0;i<=n/2;i++)
			ans=(ans*pos[i])%MOD;
	}
	else
	{
		for(ll i=0;i<n/2;i++)
			ans=(ans*pos[i])%MOD;
	}
	cout<<ans;
	return 0;
}
