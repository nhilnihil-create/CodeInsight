#include <cstdio>
#define N 111111
#define swap(a, b) { int t = a; a = b; b = t; }
int a[N];
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, ans = 0;
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) {
		if (a[i] == i) {
			swap(a[i], a[i + 1]);
			++ans;
		}
	}
	printf("%d", ans);
}
