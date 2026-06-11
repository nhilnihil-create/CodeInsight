#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN];
vector<int> con[MAXN];

void dfs(int x, int pre) {
	if (con[x].size() == 1) return;
	long long sum = 0, max_val = 0;
	for (int _i = 0; _i < con[x].size(); ++_i) {
		int y = con[x][_i];
		if (y != pre) {
			dfs(y, x);
			sum += a[y];
			max_val = max(max_val, (long long)a[y]);
		}
	}
	if (a[x] > sum || sum > 2 * a[x]) {
		puts("NO");
		exit(0);
	}
	int k = sum - a[x];
	if (k > sum - max_val) {
		puts("NO");
		exit(0);
	}
	a[x] -= k;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
	if (n == 2) {
		puts(a[0] == a[1] ? "YES" : "NO");
		return 0;
	}
	int root = 0;
	while (con[root].size() == 1) ++root;
	dfs(root, -1);
	puts(a[root] == 0 ? "YES" : "NO");
}