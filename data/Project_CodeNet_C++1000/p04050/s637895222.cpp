#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int a[MAXN], ans[MAXN];
int main() {
	int n, m;
	read(n), read(m);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		read(a[i]);
		cnt += a[i] & 1;
	}
	if (cnt > 2) {
		printf("Impossible\n");
		return 0;
	}
	if (m == 1) {
		if (a[1] == 1) printf("1\n1\n1\n");
		else printf("%d\n2\n1 %d\n", a[1], a[1] - 1);
		return 0;
	}
	for (int i = 2; i <= m - 1; i++) {
		if (a[i] & 1) {
			if (a[1] & 1) swap(a[i], a[m]);
			else swap(a[1], a[i]);
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", a[i]);
	printf("\n");
	int tot = 0;
	ans[++tot] = a[1] + 1;
	for (int i = 2; i <= m - 1; i++) {
		if (a[i] == 2) ans[++tot] = 2;
		else {
			int tmp = a[i] / 2;
			if (tmp & 1) {
				ans[++tot] = tmp / 2;
				ans[tot] *= 2;
				ans[++tot] = tmp - tmp / 2;
				ans[tot] *= 2;
			} else ans[++tot] = a[i];
		}
	}
	if (a[m] != 1) ans[++tot] = a[m] - 1;
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}