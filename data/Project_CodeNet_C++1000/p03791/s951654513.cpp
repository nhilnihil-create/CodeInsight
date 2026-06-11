#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int long long

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define REP1(i, s, cond, cal) for (signed i = signed(s); i cond; i cal)
#define REP2(i, s, n) REP1(i, s, < signed(n), ++)
#define REP3(i, n) REP2(i, 0, n)
#define rep(...) CHOOSE((__VA_ARGS__,REP1,REP2,REP3))(__VA_ARGS__)
#define rrep(i, s) rep(i, s, >= 0, --)

#define all(c) begin(c), end(c)
template<typename T>bool maxup(T& a, const T&& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool maxup(T& a, const T& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T&& b) { if (a > b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T& b) { if (a > b) { a = b; return true; }; }

#define X first
#define Y second

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }

using T = tuple<int, int, int>;
vector<T> v;
int n;

void calc() {
	int n; cin >> n;
	const int mod = 1e9 + 7;
	vector<int> facs;
	facs.push_back(1);
	{
		int x = 1;
		rep(i, 1, n + 1) {
			(x *= i) %= mod;
			facs.push_back(x);
		}
	}
	vector<int> dp(n);
	vector<int> mass;
	vector<int> xs(n);
	input(xs);
	dp[0] = xs[0];
	int pre = -1;
	int ans = 1;
	int sum = 0;
	rep(i, 1, n) {
		int d = xs[i] - xs[i - 1];
		if (!dp[i - 1]) dp[i] = d;
		else dp[i] = dp[i - 1] + d - 2;
		if (!dp[i] || i == n - 1) {
			int mass = i - pre;
			ans *= mass + sum;
			ans %= mod;
			sum += mass - 1;
			pre = i;
		}
	}
	ans *= facs[sum];
	cout << ans % mod << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	calc();
#ifdef _MSC_VER
	system("pause");
#endif
}