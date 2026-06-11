#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;
const int LOGN = 20;

int n;
long long l;

long long v[MAXN];	// Position of each hotel

bool vis[MAXN];
vector <int> g[MAXN];	// Tree built on hotels you can reach
int memo[MAXN][LOGN];	// LCA Memoization. First => Node, Second => Dist


void dfs (int x) {
	for (int i = 1; i < LOGN; ++i) {
		if (memo[x][i - 1] == -1) break;
		memo[x][i] = memo[memo[x][i - 1]][i - 1];
	}
	
	vis[x] = true;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		memo[y][0] = x;
		dfs (y);
	}
}

int getdist (int x, int y) {
	int ans = 0;
	for (int i = LOGN - 1; i >= 0; --i) {
		if (memo[x][i] != -1 && memo[x][i] <= y) {
			ans += (1 << i);
			x = memo[x][i];
		}
	}

	return ans + (x != y);
}

// L = 10
// 1 3 6 13 15 18 19 29 31

// 1 8
// 3 7


void buildgraph () {
	int r = 0;
	for (int i = 0; i < n - 1; ++i) {
		while (r < n && v[r] - v[i] <= l) ++r;

		g[r - 1].push_back (i);
	}

	memset (memo, -1, sizeof memo);
	for (int i = n - 1; i >= 0; --i)
		if (!vis[i])
			dfs (i);
}

int main () {

	cin >> n;

	for (int i = 0; i < n; ++i) scanf ("%lld", v + i);
	cin >> l;

	buildgraph ();

	int q;
	cin >> q;

	while (q--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		--x; --y;
		if (x > y) swap (x, y);

		printf ("%d\n", getdist (x, y));
	}

	return 0;
}