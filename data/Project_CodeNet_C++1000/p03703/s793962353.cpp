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
const ll L  = 0;
const ll G = 1e7;

ll n, k, a[N];
map<ll, ll> Fen;
ll ps[N], rem[N];

void Add(ll x) {
	x += L;
	for (; x < G; x += x & -x) {
		Fen[x] ++;
	}
}
ll Get(ll x) {
	x += L;
	ll res = 0;
	for (; x; x ^= x & -x) {
		res += Fen[x];
	}
	return res;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	ll ans = 0;
	vector<ll> vec;
	for (int i = 0; i <= n; i ++) {
		rem[i] = ps[i] - k * i;
		vec.pb(rem[i]);
	}
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for (int i = 0; i <= n; i ++) {
		rem[i] = lower_bound(all(vec), rem[i]) - vec.begin();
		rem[i] += 5;
	}
	for (int i = 0; i <= n; i ++) {
		ans += Get(rem[i]);
		Add(rem[i]);
	}
	cout << ans;
	
}