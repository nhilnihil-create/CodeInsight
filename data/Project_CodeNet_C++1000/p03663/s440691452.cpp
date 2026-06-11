#pragma GCC optimize("unroll-loops,Ofast")
#pragma GCC target("avx,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7;
ll rn = 999;
bool ask(ll n) {
	cout << "? " << n << endl;
	char t;
	cin >> t;
	return t == 'Y';
}
void ans(ll n) {
	cout << "! " << n << endl;
	exit(0);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll r = 1;
	while(r < 1e11 && ask(r)) r *= 10;
	if(r == 1e11) {
		ll q = 10;
		while(q < 1e11 && !ask(q-1)) q *= 10;
		r = q;
	}
	ll a = r;
	for(ll i = 1ll<<35; i>>=1;)
		if(a+i < 10ll*r && !ask(a+i)) a += i;
	ans((a+1)/10);
	return 0;
}
