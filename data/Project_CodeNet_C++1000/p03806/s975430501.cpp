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

ll dp[415][415];

void solve_abc_d() {
	ll n, m, x, k;
	ll ma, mb;
	cin >> n >> ma >> mb;

	V a(n), b(n), c(n);
	rep(i, n) {
		cin >> a[i] >> b[i] >> c[i];
	}

	rep(i, 415)rep(j, 415) {
		dp[i][j] = INF;
	}

	dp[0][0] = 0;
	rep(i, n) {
		rrep(j, 10 * n, 0)rrep(k, 10 * n, 0) {
			dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
		}
	}

	ll na = ma;
	ll nb = mb;
	ll ans = INF;
	while(1){
		if ((na >= 415) || (nb >= 415)) {
			break;
		}
		if (dp[na][nb] != INF) {
			ans = min(ans, dp[na][nb]);
		}
		na += ma;
		nb += mb;
	}

	if (ans == INF) ans = -1;

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_d();

	return 0;
}
