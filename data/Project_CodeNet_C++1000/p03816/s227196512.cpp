#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll n;
	cin>>n;
	ll fre[1000000]{};
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i],fre[arr[i]]++;
	ll sum=0;
	for(ll i=0;i<1000000;i++)
		if(fre[i]!=0)
			sum+=fre[i]-1;
	if(sum%2==0)
		cout<<n-sum;
	else
		cout<<n-sum-1;
	return 0;
}

