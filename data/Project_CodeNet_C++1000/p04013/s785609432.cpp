#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
	int n, a;
	cin >> n >> a;
	int x[50];
	rep(i, n) cin >> x[i];
	vector<vector<vector<ll>>> dp(n + 1,
		vector<vector<ll>>(n + 1,
			vector<ll>(n * 50 + 1, 0ll)));
	dp[0][0][0] = 1ll;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= n * 50; k++) {
				if(j >= 1 && k >= x[i])
					dp[i+1][j][k] += dp[i][j-1][k-x[i]];
				dp[i+1][j][k] += dp[i][j][k];
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += dp[n][i][i * a];
	}
	cout << ans << endl;
}
