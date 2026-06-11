#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 305;
int g[MAXN][MAXN], pro[MAXN];
bool be_deleted[MAXN];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; i++)
		for (register int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);
	int ans = n;
	for (register int i = 1; i <= m; i++) {
		memset(pro, 0, sizeof(pro));
		for (register int j = 1; j <= n; j++)
			for (register int k = 1; k <= m; k++) {
				int temp = g[j][k];
				if (!be_deleted[temp]) {
					pro[temp]++;
					break;
				}
			}
		int pos = int(max_element(pro+1, pro+1+m) - pro);
		ans = min(ans, pro[pos]);
		be_deleted[pos] = true;
	}
	printf("%d", ans);
	return 0;
}