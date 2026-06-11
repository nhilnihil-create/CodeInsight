#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
//ll mod = 1000000007;
//ll mod = 998244353;

vector<ll> cnt(700010);

void add(ll i, ll x) {
	i += 262143;
	cnt[i] += x;
	while (i > 0) {
		i = (i - 1) / 2;
		cnt[i] = cnt[i * 2 + 1] + cnt[i * 2 + 2];
	}
}

ll query(ll a, ll b, ll k, ll l, ll r) {
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return cnt[k];
	else {
		ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
		ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return c1 + c2;
	}
}

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<ll> s(n + 1);
	s[0] = 0;
	for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i] - k;
	map<ll, ll> mp;
	for (int i = 0; i <= n; i++) {
		s[i] += k * n;
		mp[s[i]]++;
	}
	vector<ll> t(n + 1);
	for (int i = 0; i <= n; i++) t[i] = s[i];
	sort(all(t));
	for (int i = 1; i <= n; i++) {
		if (t[i] != t[i - 1]) mp[t[i]] += mp[t[i - 1]];
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		s[i] = mp[s[i]];
		ll res = query(262143, 262144 + s[i], 0, 262143, 524287);
		ans += res;
		add(s[i], 1);
	}
	cout << ans << endl;
}
