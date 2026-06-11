#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 7, W = 3e4;
int n, x, a[maxn], b[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		a[i] = b[n - i + 1] = i * W;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		a[x] -= (n - i);
	}
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]); printf("\n");
	for (int i = 1; i <= n; ++i) printf("%d ", b[i]); printf("\n");
	return 0;
}