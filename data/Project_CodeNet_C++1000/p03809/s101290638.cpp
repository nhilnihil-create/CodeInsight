#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)
#define NR 101000

typedef long long i64;

vector<int> e[NR];
int n, a[NR], d[NR];
bool valid = true;

i64 dfs(int x, int fa) {
	if (d[x] == 1) {
		return a[x];
	}
	i64 sum = 0, mx = 0;
	for (int v : e[x]) if (v != fa) {
		i64 tmp = dfs(v, x);
		sum += tmp; mx = max(mx, tmp);
	}
	if (a[x] > sum || (sum + 1) / 2 > a[x]) { valid = false; return 0; }
	i64 delta = sum - a[x];
	if (delta > (mx * 2 <= sum ? sum / 2 : sum - mx)) { valid = false; return 0; }
	return sum - 2 * delta;
}

int main() {
	//freopen("10C.in", "r", stdin);
	scanf("%d", &n);
	iter(i, n) scanf("%d", &a[i]);
	iter(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		++d[x], ++d[y];
	}
	int root = -1;
	iter(i, n) if (d[i] != 1) root = i;
	if (root == -1) {
		if (a[1] == a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	if (dfs(root, 0) != 0 || !valid) puts("NO");
	else puts("YES");
	return 0;
}