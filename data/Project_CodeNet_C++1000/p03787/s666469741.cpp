#include <cstdio>
#include <vector>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)

const int NR = 1e5 + 100;

vector<int> e[NR];
int n, m, col[NR], C[2];
bool bi;

void dfs(int x, bool c) {
	col[x] = c; ++C[c];
	for (int v : e[x]) {
		if (col[v] == -1) {
			dfs(v, !c);
		} else if (col[x] == col[v]) {
			bi = false;
		}
	}
}

int main() {
	//freopen("11C.in", "r", stdin);
	scanf("%d%d", &n, &m);
	iter(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	iter(i, n) col[i] = -1;
	int d0 = 0, d1 = 0, d2 = 0;
	iter(i, n) if (col[i] == -1) {
		C[0] = C[1] = 0; bi = true;
		dfs(i, 0);
		if (bi) {
			if (C[1]) ++d2;
			else ++d0;
		} else ++d1;
	}
//	printf("%d %d %d\n", d0, d1, d2);
	printf("%lld\n", 2ll * d0 * n - 1ll * d0 * d0 + 2ll * d2 * d1 + 1ll * d1 * d1 + 2ll * d2 * d2); 
	return 0;
}
