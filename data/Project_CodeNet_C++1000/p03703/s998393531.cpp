#include <bits/stdc++.h>

typedef long long ll;
const int N = 200054;

int n;
ll I, a[N], b[N];

void merge_sort(int L, int R) {
	if (L + 1 == R) return;
	int M = (L + R) / 2, i = L, j = M, c = L;
	merge_sort(L, M), merge_sort(M, R), memcpy(b + L, a + L, (R - L) << 3);
	for (; i < M && j < R; a[c++] = (b[i] <= b[j] ? b[i++] : (I += M - i, b[j++])));
	i < M ? memcpy(a + c, b + i, (M - i) << 3) : memcpy(a + c, b + j, (R - j) << 3);
}

int main() {
	int i, k;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; ++i) scanf("%lld", a + i), a[i] += a[i - 1] - k;
	merge_sort(0, ++n), printf("%lld\n", n * (n - 1ll) / 2 - I);
	return 0;
}