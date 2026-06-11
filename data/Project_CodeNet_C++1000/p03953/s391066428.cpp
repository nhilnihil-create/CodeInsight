#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
bool visited[MAXN];
int n, m, num[MAXN], tmp[MAXN], dest[MAXN];
long long k, x[MAXN], delta[MAXN], ans[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		delta[i] = x[i] - x[i - 1];
		num[i] = i;
	}
	scanf("%d%lld", &m, &k);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		swap(num[x], num[x + 1]);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		int tot = 0, pos = i;
		while (!visited[pos]) {
			visited[pos] = true;
			tmp[tot++] = pos;
			pos = num[pos];
		}
		for (int j = 0; j < tot; j++)
			dest[tmp[j]] = tmp[(j + k) % tot];
	}
	for (int i = 1; i <= n; i++)
		ans[i] = delta[dest[i]];
	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
		printf("%lld.0\n", ans[i]);
	}
	return 0;
}