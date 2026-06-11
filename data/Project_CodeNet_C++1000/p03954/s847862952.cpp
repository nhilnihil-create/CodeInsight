#include <stdio.h>

const int N = 1e5 + 10;

int n, a[N << 1], b[N << 1];

inline bool check(int x) {
	for (int i = 1; i < n << 1; ++ i) 
		b[i] = a[i] <= x;
	if (b[n - 1] == b[n] || b[n + 1] == b[n])
		return b[n];
	for (int i = 1; i < n - 1; ++ i) {
		if(b[n - i] == b[n - i - 1]) return b[n - i];
		if(b[n + i] == b[n + i + 1]) return b[n + i];
	}
	return b[1];
}

int main() {
	//freopen("pyramid.in", "r", stdin);
	//freopen("pyramid.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n << 1; ++ i)
		scanf("%d", &a[i]);

	int l = 1, r = (n << 1) - 1, ans; 
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1; 
	}
	printf("%d\n", ans);

	return 0;
}
