#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ll s=0;
	for(ll i=1;i<n;i++)
	{
		s += min((arr[i]-arr[i-1])*a,b);
	}
	cout<<s<<"\n";
}