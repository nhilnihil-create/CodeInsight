#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7, i2 = (mod+1)/2;
int x[maxn], y[maxn], w[maxn], z[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for(int i = 0; i < n; i++) x[i+1] = x[i] + (s[i]=='A') + 1;
	for(int i = 0; i < m; i++) y[i+1] = y[i] + (t[i]=='A') + 1;
	int q;
	cin >> q;
	int a, b, c, d;
	while(q--) {
		cin >> a >> b >> c >> d;
		--a, --c;
		cout << ((x[b]-x[a])%3 == (y[d]-y[c])%3 ? "YES\n" : "NO\n");
	}
	return 0;
}
