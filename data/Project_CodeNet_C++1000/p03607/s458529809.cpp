#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
	fast;
	ll n,ans=0;
	cin>>n;
	ll arr[n];
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	for(auto i:mp)
		if(i.second%2==1)
			ans++;
	cout<<ans;
	return 0;
}
