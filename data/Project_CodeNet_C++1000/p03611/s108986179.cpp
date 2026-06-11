#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
	fast;
	ll n;
	cin>>n;
	vector<ll> arr(n),fre(100001,0),max(100001,0);
	ll x;
	for(int i=0;i<n;i++)
		cin>>arr[i],fre[arr[i]]++;
	max[0]=fre[0]+fre[1];
	x=max[0];
	for(int i=1;i<100000;i++)
	{
		max[i]=fre[i]+fre[i-1]+fre[i+1];
		if(max[i]>x)
			x=max[i];
	}
	cout<<x;
	return 0;
}

