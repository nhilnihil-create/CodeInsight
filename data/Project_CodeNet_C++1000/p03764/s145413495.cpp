#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main(){
	static ll n,m;
	static ll x[100010],y[100010];
	scanf("%lld%lld",&n,&m);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&x[i]);
	}
	for(int i = 0 ; i < m ; i ++){
		scanf("%lld",&y[i]);
	}
	
	ll X = 0, Y = 0;
	for(int i = 0 ; i+1 < n ; i ++){
		ll t = (i+1)*(n-(i+1));
		t %= MOD;
		t *= x[i+1]-x[i];
		X += t; X %= MOD;
	}
	for(int i = 0 ; i+1 < m ; i ++){
		ll t = (i+1)*(m-(i+1));
		t %= MOD;
		t *= y[i+1]-y[i];
		Y += t; Y %= MOD;
	}
	cout << (X*Y)%MOD << endl;
}