#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
const int N = 500;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	VVV dp(n + 1, VV(N, V(N, upper)));
	dp[0][0][0] = 0;
	V d(n), e(n), f(n);
	rep(i, n) {
		cin >> d[i] >> e[i] >> f[i];
	}
	rep(i, n) rep(j, N - 50) rep(k, N - 50) {
		chmin(dp[i + 1][j + d[i]][k + e[i]], dp[i][j][k] + f[i]);
		chmin(dp[i + 1][j][k], dp[i][j][k]);
	}
	int ans = upper;
	rep1(i, 45) {
		chmin(ans, dp[n][a * i][b * i]);
	}
	cout << (ans == upper ? -1 : ans) << endl;
	return 0;
}