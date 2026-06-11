#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 2e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

ll n, a[N], k, m;
ll y[N], p[N], o[N], ans[N];
ll G[N];
ll C = 1;
ll cyc[N];
ll M[N];
vector<ll> V[N];
ll pos[N], end[N];
ll Z[N];
void f() {
	for (int i = 1; i <= n; i ++) 
		p[i] = i; 
	for (int i = 1; i <= m; i ++) 
		swap(p[o[i]], p[o[i] + 1]);
	for (int i = 1; i <= n; i ++) {
		if (M[i]) continue;
		if (i == p[i]) {
			M[i] = 1;
			C ++;
			cyc[i] = C;
			pos[i] = 0;
			V[C].pb(i);
			continue;
		}
		ll x = i;
		ll y = p[i];
		C ++;
		cyc[x] = C;
		pos[x] = V[C].size();
		V[C].pb(x);
		M[x] = 1;
		while (y ^ x) {
			cyc[y] = C;
			pos[y] = V[C].size();
			V[C].pb(y);
			M[y] = 1;
			y = p[y];
		}
	}
	for (int i = 1; i <= n; i ++) {
		ll cc = cyc[i];
		ll ps = pos[i];
		ll res = ps + k;
		res %= ll(V[cc].size());
		ll id = V[cc][res];
		ans[i] = y[id];
	}
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) 
    	cin >> a[i];
	for (int i = 1; i <= n; i ++) 
		y[i] = a[i] - a[i - 1]; 
	cin >> m >> k;
	for (int i = 1; i <= m; i ++) 
		cin >> o[i];
	f();
	cout << ans[1] << '\n';
	Z[1] = ans[1];
	for (int i = 2; i <= n; i ++) {
		Z[i] = ans[i] + Z[i - 1];
		cout << Z[i] << '\n';
	}
    return (0);
}