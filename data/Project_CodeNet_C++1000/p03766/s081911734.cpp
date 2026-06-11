#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll MOD = 1000000007;
const int MN = 1000010;

inline void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	int n; cin >> n;
	vector<ll> dp(n + 1), pref(n + 1);
	ll two = (ll)(n - 1) * (n - 1) % MOD;
	dp[1] = pref[1] = n;
	dp[2] = (ll)n * n % MOD; pref[2] = (pref[1] + dp[2]) % MOD;

	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i-1]; //a1=1
		add(dp[i], two); //a1!=1,a2!=1
		add(dp[i], n - i + 2); //a1!=1,a2=an=1
		add(dp[i], pref[i - 3]);
		pref[i] = pref[i-1];
		add(pref[i], dp[i]);
	}

	cout << dp[n] << endl;
	return 0;
}