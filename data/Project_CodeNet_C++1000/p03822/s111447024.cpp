#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const int inf = 1145141919810931;
typedef pair<int, int> P;
typedef pair<P, int>PP;
typedef pair<int, char>PC;
struct edge { int to, cost; };
vector<int>V[100005];
int dp[100005];
int memo(int now) {
	if (dp[now] != inf)return dp[now];
	int res;
	if (!V[now].size())res = 0;
	else {
		vector<int>x;
		rep(i, V[now].size()) {
			x.push_back(memo(V[now][i]));
		}
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());
		rep(i, x.size()) {
			x[i] += i + 1;
		}
		sort(x.begin(), x.end());
		res = x[x.size()-1];
	}
	return dp[now] = res;
}

signed main() {
	int n; cin >>  n;
	rep(i, n - 1) {
		int a; cin >> a;
		V[a - 1].push_back(i+1);
	}
	fill(dp, dp + n, inf);
	memo(0);
	cout << dp[0] << endl;
}