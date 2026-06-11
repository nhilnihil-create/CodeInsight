#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 4e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

ll a[N], b[N], n, A, B;

bool ok(ll x) {
	ll C = A - B;
	for (int i = 1; i <= n; i ++) 
		b[i] = a[i] - x * B;
	ll rem = 0;
	for (int i = 1; i <= n; i ++) {
		if (b[i] <= 0) continue;
		rem += (b[i] + C - 1) / C;
	}
	return rem <= x;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	ll H = 2e9, L = 0, M;
	for (int i = 0; i < 5; i ++) {
		if (ok(i)) {
			return cout << i, 0;
		}
	}
	while (H - L > 1) {
		M = (H + L) >> 1;
		if (ok(M)) H = M;
		else L = M;
	}
	if (ok(L)) H = L;
	cout << H;
	
	
}
