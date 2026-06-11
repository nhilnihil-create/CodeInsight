#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	set<ll>arr;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		arr.insert(x);
	}
	
	if(arr.size()%2!=0)
		cout<<arr.size()<<"\n";
	else
		cout<<arr.size()-1<<"\n";
}