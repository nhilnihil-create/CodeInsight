#include<bits/stdc++.h>
using namespace std;
#define MAXN	505
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int a[MAXN], b[MAXN], ans[MAXN * MAXN];
bool cmp(int x, int y) {
	return a[x] < a[y];
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]); b[i] = i;
		ans[a[i]] = i;
	}
	sort(b + 1, b + n + 1, cmp);
	int pos;
	pos = 1;
	for (int i = 1; i <= n; i++) {
		int all = b[i] - 1;
		for (int j = 1; j <= all; j++) {
			while (ans[pos]) pos++;
			ans[pos] = b[i];
		}
		if (pos > a[b[i]]) {
			printf("No\n");
			return 0;
		}
	}
	pos = n * n;
	for (int i = n; i >= 1; i--) {
		int all = n - b[i];
		for (int j = 1; j <= all; j++) {
			while (ans[pos]) pos--;
			ans[pos] = b[i];
		}
		if (pos < a[b[i]]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n * n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}