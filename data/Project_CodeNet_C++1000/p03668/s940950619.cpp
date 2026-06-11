#include "bits/stdc++.h"
#include<cassert>
#pragma warning(disable:4996)
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MRE assert(0)
const int mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P, int>PP;
vector<int>G[100006];
int dp[100006];

int memo(int now,int par) {
	if (dp[now] != inf)return dp[now];
	int res = 0;
	for (int e : G[now]) {
		if (e == par)continue;
		res ^= (memo(e, now) + 1);
	}
	return dp[now] = res;

}

signed main() {
	int n; cin >> n;
	rep(i, n - 1) {
		int x, y; cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	rep(i, n)dp[i] = inf;
	memo(0, -1);
	if (dp[0])puts("Alice");
	else puts("Bob");
}