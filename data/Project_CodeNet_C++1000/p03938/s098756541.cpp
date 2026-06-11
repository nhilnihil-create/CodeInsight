#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
int p[maxn], a[maxn], b[maxn];

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; ++i)
		a[i] = 40000 * i;
	for (int i = 1; i <= n; ++i)
		b[p[i]] = (n - p[i] + 1) * 40000 + i;
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	printf("\n");
}
