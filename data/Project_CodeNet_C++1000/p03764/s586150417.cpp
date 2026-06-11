#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long ll;
ll n, m;
int main(){
	cin >> n >> m;
	ll x=0;
	for(ll i = 0; i<n; i++){
		ll a; cin >> a;
		x += a*(n-2*i-1);
		x %= mod; x += mod; x %= mod;
	}
	ll y=0;
	for(ll i = 0; i<m; i++){
		ll a; cin >> a;
		y += a*(m-2*i-1);
		y %= mod; y += mod; y %= mod;
	}
	cout << (x*y)%mod;
}
