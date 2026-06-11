#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
    sort(arr,arr+n);
    ll cnt=0;
	for(ll i=n-1;i>=0;i--)
	{
		sum+=arr[i];
		cnt++;
		if(cnt==k)
		{
			break;
		}
	}
	cout<<sum<<endl;
}