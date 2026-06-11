#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	ll n;
	cin>>n;
	ll arr[n];
	ll ans[2],k=0;
	unordered_map<int,int> mp;
	set<int> s;
	for(int i=0;i<n;i++)
		cin>>arr[i],mp[arr[i]]++,s.insert(arr[i]);
	sort(arr,arr+n);
	ll m=s.size();
	if(!(n>=(m+2)))
	{
		cout<<"0";
		return 0;
	}
	for(int i=n-1;i>=0&&k<2;i--)
	{
		if(mp[arr[i]]>=2)
			ans[k]=arr[i],mp[arr[i]]-=2,k++;
	}
	cout<<ans[0]*ans[1];
	return 0;
}

