#include<cstdio>
#include<algorithm>
int a[100000],b[100000];
int main() {
	int n, t, i, ans = 1;
	scanf("%d%d", &n, &t);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	b[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--) b[i] = a[i] > b[i + 1] ? a[i] : b[i + 1];
	for (i = 0; i < n; i++)b[i] -= a[i];
	std::sort(b, b + n);
	for (i = n - 2; i >= 0 && b[i] == b[i + 1]; i--)ans++;
	printf("%d", ans);
	return 0;
}