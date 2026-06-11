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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
const int N = 10101;
int main() {
	int n;
	cin >> n;
	V a(n);
	rep(i, n) {
		cin >> a[i];
	}
	VE<VE<bool>> dp(n + 1, VE<bool>(N, false));
	dp[0][0] = true;
	rep(i, n) rep(j, N) {
		if (dp[i][j]) {
			dp[i + 1][j + a[i]] = true;
			dp[i + 1][j] = true;
		}
	}
	int ans = 0;
	rep(i, N) {
		if (dp[n][i] && i % 10 != 0) chmax(ans, i);
	}
	cout << ans << endl;
	return 0;
}