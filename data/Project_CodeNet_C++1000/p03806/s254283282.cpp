#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int memo[44][444][444];
int n, ma, mb;
vi a, b, c;

int dp(int i, int s, int t) {
	if (s < 0 || t < 0)return INF;
	if (memo[i][s][t])return memo[i][s][t];
	if (i == 0 && s == 0 && t == 0)return 0;
	if (i == 0)return INF;

	int pre = dp(i - 1, s, t);
	int now = dp(i - 1, s - a[i - 1], t - b[i - 1]) + c[i - 1];
	memo[i][s][t] = min(pre, now);
	return memo[i][s][t];
}

int main() {

	cin >> n >> ma >> mb;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	rep(i, n)cin >> a[i] >> b[i] >> c[i];

	int mma = ma, mmb = mb;
	int ans = INF;
	while (mma <= n * 10 && mmb <= n * 10) {
		ans = min(ans, dp(n, mma, mmb));
		mma += ma;mmb += mb;
	}

	if (ans == INF)ans = -1;
	cout << ans << endl;

}