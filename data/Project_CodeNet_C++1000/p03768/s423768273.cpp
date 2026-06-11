#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, m, q, a, b, u, d, c[100010];
vector<int> vec[100010];
int dp[15][100010];
signed main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cin >> q;
	REP(i, q) {
		cin >> u >> d >> c[i];
		dp[d][u] = i;
	}
	for (int i = 10; i > 0; i--) {
		REP(j, n) {
			for (int k : vec[j]) {
				dp[i - 1][k] = max(dp[i - 1][k], dp[i][j]);
			}
			dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
	REP(j, n) {
		if (dp[0][j])cout << c[dp[0][j]] << endl;
		else cout << 0 << endl;
	}
	return 0;
}