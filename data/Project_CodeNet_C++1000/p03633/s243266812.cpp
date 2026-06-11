#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll LCD(ll a,ll b){
	if(a<b) swap(a,b);
	while(b){
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	vector<ll>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	ll lcm = 1;
	for(int i=0; i<n; i++){
		ll lcd = LCD(arr[i],lcm);
		lcm = lcm*(arr[i]/lcd);
	}
	cout<<lcm;
}