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
	ll arr[n],cnt4=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]%4==0)
			cnt4++;
		if(arr[i]%2==0)
			cnt2++;
	}
	if(cnt4>=n/2||(cnt4>=(n-cnt2)))
	{
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}

