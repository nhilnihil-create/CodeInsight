#ifdef ONLINE_JUDGE

#include "bits/stdc++.h"
using namespace std;

#define ui unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(v) v.begin(), v.end()

#define speed ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ld PI = 3.1415926535897932384626;
ll MOD = 1000000007;
const ld EPS = 1e-9;
const int N = 3e5 + 7;

inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ui setBits(ui v) { ui c; for(c = 0 ; v; ++c) v &= (v - 1); return c; }
inline bool isPowerOfTwo(ui v) { return (v && !(v & (v - 1))); }
ll power(ll base, ull exp, ll mod = MOD) { 
	ll res = 1; base %= mod; 
	while(exp) { 
		if(exp & 1) res = (res * base)%mod; 
		exp >>= 1; base = (base * base)%mod; 
	} 
	return res; 
}
ll modInv(ll a, ll mod = MOD) { 
	if(mod == 1) return 0; 
	ll x = 1, y = 0, m = mod; 
	while(a > 1) { 
		ll q = a/m, t = m; m = a%m; a = t; t = y; y = x - q * y; x = t; 
	} 
	if(x < 0) x += mod; 
	return x; 
}
inline ui iabs(int x) { ui y = x; return (y > 0) ? y : -y; }
inline ll add(ll a, ll b, ll mod = MOD) { ll res = (a%mod + b%mod)%mod; return res; }
inline ll sub(ll a, ll b, ll mod = MOD) { ll res = (a%mod - b%mod + mod)%mod; return res; }
inline ll mult(ll a, ll b, ll mod = MOD) { ll res = (a%mod * b%mod)%mod; return res; }
inline ll div(ll a, ll b, ll mod = MOD) { ll res = (a%mod * modInv(b, mod))%mod; return res; }

#else

#include "custom.h"
using namespace std;

#endif

void openf() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif	
}

int main() {
	speed;
	openf();
	ll n, sum = 0;
	cin >> n;
	vector<ll> arr(n);

	for(int i = 0 ; i < n ; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll m;
	cin >> m;
	while(m--) {
		ll p, x;
		cin >> p >> x;
		cout << sum - arr[p - 1] + x << endl;
	}
	return 0;
} 