#include <bits/stdc++.h>

const int kN = 2e5 + 5;

int n, a[kN];
bool Check(int mid) {
	for(int i = 0; i < n - 1; ++i) {
		if((a[n + i] > mid) == (a[n + i + 1] > mid)) return (a[n + i] > mid);
		if((a[n - i] > mid) == (a[n - i - 1] > mid)) return (a[n - i] > mid);
	}
	return a[1] > mid;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < 2 * n; ++i) scanf("%d", a + i);
	int l = 1, r = 2 * n - 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(Check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%d", l);
	return 0;
}