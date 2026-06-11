#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
	fast;
	ll n,k,dis=0;
	cin>>n>>k;
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++){
		dis+=2*min( arr[i],abs(k-arr[i]) );
	}
	cout<<dis;
	return 0;
}
