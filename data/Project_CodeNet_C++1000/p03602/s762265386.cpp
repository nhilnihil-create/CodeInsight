#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[310][310], chk[310][310];
long long res;
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (w[i][j] > w[i][k] + w[k][j]) {
					puts("-1");
					return 0;
				}
				if (w[i][j] == w[i][k] + w[k][j] && i != k && k != j)chk[i][j] = 1;
			}
		}
	}
	for (i = 1; i <= n; i++)for (j = i + 1; j <= n; j++)if (!chk[i][j])res += w[i][j];
	printf("%lld\n", res);
}