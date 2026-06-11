#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
ll n,m,k;
vector<ll> arrange(vector<ll> prev, vector<ll> com){
	vector<ll> res(n+1);
	for(ll i=1;i<=n;i++){
		res[i] = prev[ com[i] ];
	}
	return res;
}
int main(){
	cin>>n;
	vector<ll> x(n+1),d(n+1),bas[63],st(n+1);
	bas[0].pb(0);
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		bas[0].pb(i);
		st[i]=i;
	}
	cin>>m>>k;
	vector<ll> a(m+1);
	for(ll i=1;i<=m;i++){
		cin>>a[i];
	}
	d[0]=0;
	for(ll i=1;i<=n-1;i++){
		d[i]=x[i+1]-x[i];
	}
	for(ll i=1;i<=m;i++){
		swap(bas[0][a[i]-1],bas[0][a[i]]);
	}
	for(ll i=1;i<=60;i++){
		bas[i] = arrange(bas[i-1],bas[i-1]);
	}
	for(ll i=0;i<=60;i++){
		if(k%2==1){
			st = arrange(st,bas[i]);
		}
		k = k/2;
	}
	d = arrange(d, st);
	ll pos = x[1];
	for(ll i=0;i<n;i++){
		pos+=d[i];
		cout<<pos<<endl;
	}
	return 0;
}