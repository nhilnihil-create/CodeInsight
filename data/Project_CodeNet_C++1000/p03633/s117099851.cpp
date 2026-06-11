#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	ll n,ans=0;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ans=arr[0];
	for(int i=1;i<n;i++)
	{
		ans=(arr[i])*(ans/gcd(arr[i],ans));
	}
	cout<<ans;
	return 0;
}

