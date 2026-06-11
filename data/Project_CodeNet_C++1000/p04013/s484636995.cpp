#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = 1000000000;
ll inf = 1000000000000;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n, m;
	cin >> n >> m;
	int i;
	int a[110];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll dp[55][55][3501];
	dp[0][0][0] = 1;
	for (i = 0; i < n; i++) { // i番目まで見て
		for (int j = 0; j <= i; j++) { // j個ピックした時の
			for (int k = 0; k <= 2500; k++) { // 総和がkになるようなものの数え上げ
				dp[i + 1][j][k] += dp[i][j][k];
				dp[i + 1][j + 1][k + a[i]] += dp[i][j][k];
			}

		}
	}
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		ans += dp[n][i][i * m];
	}
	cout << ans;
	return(0);
}