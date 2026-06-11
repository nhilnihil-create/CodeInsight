#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5, maxp = 1e9 - maxn;
int n, a[maxn], b[maxn], p[maxn];
int main() {
	scanf("%d", &n);
	int x = maxp / (n - 1);
	a[1] = maxn, b[n] = maxn;
	for(int i = 1; i < n; ++ i)
		a[i + 1] = a[i] + x, b[n - i] = b[n - i + 1] + x;
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &p[i]), a[p[i]] -= n - i;
	for(int i = 1; i <= n; ++ i)
		printf("%d ", a[i]);
	puts("");
	for(int i = 1; i <= n; ++ i)
		printf("%d ", b[i]);
	puts("");
}