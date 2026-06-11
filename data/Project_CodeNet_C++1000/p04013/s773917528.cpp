#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[55][55][3600];
// dp[i][j][k] := i枚まで見てj枚使ってkが作れる個数

int main(void) {
	ll n, a;
	cin >> n >> a;
	ll x[n];
	rep (i, n) cin >> x[i];

	
	dp[0][0][0] = 1;
	rep (i, n) rep (j, n) rep (k, 2500) {
		dp[i + 1][j][k] += dp[i][j][k];
		dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
	}

	ll ans = 0;
	rrep (i, n) {
		ans += dp[n][i][i * a];
	}

	cout << ans << endl;
	return 0;
}