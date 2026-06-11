#include <bits/stdc++.h>
using namespace std;

string a;
int n;
int edge[200010][26];
int dp[200010];
int nxt[200010];
char c[200010];

int dfs(int from) {
	if(dp[from] != -1) return dp[from];
	int ret = 1e9;
	for(int i = 25; i >= 0; --i) {
		int to = dfs(edge[from][i]) + 1;
		if(to <= ret) {
			ret = to;
			nxt[from] = edge[from][i];
			c[from] = (char)('a' + i);
		}
	}
	dp[from] = ret;
	return ret;
}

int main() {
	cin >> a;
	a = "$" + a;
	n = a.size();
	int nidx[26]; for(int i = 0; i < 26; ++i) nidx[i] = n;
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) {
			edge[i][j] = nidx[j];
		}
		if(i > 0) {
			nidx[a[i] - 'a'] = i;
		}
	}
	for(int i = 0; i < 200010; ++i) {
		dp[i] = -1;
	}
	dp[n] = 0;
	dfs(0);
	string ans;
	int now = 0;
	while(now < n) {
		ans += c[now];
		now = nxt[now];
		if(now == n) break;
	}
	cout << ans << '\n';
	return 0;
}