#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m, E, ans;
int fir[N], nex[N], arr[N], dp[N], lin[N];

inline void Add_Edge(int x, int y) {
	nex[++E] = fir[x];
	fir[x] = E; arr[E] = y;
}

void dfs(int x) {
	dp[x] = 0;
	for (int i = fir[x]; i; i = nex[i]) {
		dfs(arr[i]);
		dp[x] = max(dp[x], dp[arr[i]] + 1);
	}
//	cout << x << ' ' << dp[x] << endl;
	if (dp[x] == m - 1 && !lin[x]) dp[x] = -1, ++ans;
}

int main() {
	cin >> n >> m >> ans;
	ans = (ans != 1);
	lin[1] = 1;
	for (int i = 2; i <= n; ++i) {
		int to;
		scanf("%d", &to);
		Add_Edge(to, i);
		if (to == 1) lin[i] = 1;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
