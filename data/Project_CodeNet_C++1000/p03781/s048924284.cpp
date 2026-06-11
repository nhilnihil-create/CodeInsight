#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
ll product(ll n){
	return (n*(n+1))/2;
}
int main(){
	nes;
	ll x;
	cin>>x;
	ll l=0,h=1e9+5;
	while(l<=h){
		ll mid=l+(h-l)/2;
		ll check=product(mid);
		if(check==x){
			//indx=mid;
			//break;
			h=mid-1;
		}
		else if(check<x) l=mid+1;
		else h=mid-1;
	}
	cout<<l;
	return 0;
}