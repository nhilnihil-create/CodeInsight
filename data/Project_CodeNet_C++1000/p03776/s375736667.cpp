#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

vector<double> dp(55, 0);

ull binomial(ull N, ull K) {
	if (K < 0 || N < K) return 0;
	ull ret = 1;
	for (ull i = 1; i <= K; ++i) {
		ret *= N--;
		ret /= i;
	}
	return ret;
}

void solve_abc_d() {
	ll n, m;
	ll a, b;
	//ll x, y;
	ll k;
	ll l_ans = 0;

	cin >> n >> a >> b;
	V v(n);
	rep(i, n) {
		cin >> v[i];
	}

	sort(v.rbegin(), v.rend());
	map<ll, ll> d;
	rep(i, a) {
		dp[i + 1] = (i * dp[i] + v[i])/(i + 1);
		++d[v[i]];
	}

	ll value = d.begin()->first;
	ll size = d.begin()->second;
	ll add = 0;
	for (ll i = a; i < n; i++) {
		if (v[i] == value) {
			add++;
		}
	}
	ull ans = 0;
	if (size == a) {
		for (ll i = a; i <= min(b, size+add); i++) {
			ans += binomial((ull)size + add, (ull)i);
		}
	}
	else {
		ans = binomial((ull)size + add, (ull)size);
	}

	cout << dp[a] << "\n";
	cout << ans << "\n";
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
