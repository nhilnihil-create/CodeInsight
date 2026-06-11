#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, p, a = 1, b = 0;
	cin >> n >> p;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(t&1) tie(a, b) = pair<ll, ll>{a+b, b+a};
		else tie(a, b) = pair<ll, ll>{a+a, b+b};
	}
	cout << (p?b:a);
	return 0;
}
