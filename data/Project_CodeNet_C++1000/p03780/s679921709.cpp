#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>


ll n, k, s[5100], ans;
ll dat[1100010];
void add(ll x, ll a) {
	x++;
	for (ll i = x; i <= 5100; i += i & -i) dat[i] += a;
}

ll sum(ll x) {
	if (x < 0)return 0;
	x++;
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i) res += dat[i];
	return res;
}


bool dp[5100][5100]; //上限5001
int main() {
	cin >> n >> k;
	REP(i, n)cin >> s[i];
	dp[0][0] = 1;
	add(0, 1);
	REP(i, n) {
		REP(j, k + 1) {
			if (dp[i][j]) {
				dp[i + 1][j] = true;
				dp[i + 1][min((ll)5001, j + s[i])] = true;
			}
		}
	}
	REPR(i, n - 1) {
		bool ok = true;
		REP(j, k) {
			if (dp[i][j]) {
				if (sum(max(0ll, k - 1 - j)) - sum(k - s[i] - 1 - j) > 0) {
					ok = false;
				}
			}
		}
		if (ok)ans++;
		REPR(j, 5001) {
			if (sum(j) - sum(j - 1) > 0)add(min((ll)5001, j + s[i]), 1);
		}
	}
	cout << ans << endl;
}
