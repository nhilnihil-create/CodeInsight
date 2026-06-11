#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	//ll ps[n-1];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];

	}
	ll c=0;
	//for(ll i=0;i<n-1;i++)
	//	ps[i]=arr[i]+arr[i+1];
	//ll min =2000000009;
	for(ll i=0;i<n-1;i++)
	{
		if(arr[i]+arr[i+1]>x)
		{
			c += arr[i]+arr[i+1]-x;
			arr[i+1]-=arr[i]+arr[i+1]-x;
			if(arr[i+1]<0)
				arr[i+1]=0;	
		}	
	}
	cout<<c<<"\n";

}