//AT2165
#include <cstdio>

const int MAXN = (int)1e5;
int n, a[2*MAXN+5];

inline bool check(int x) {
	for (int i = 0; i < n-1; i++) {
		if ((a[n+i] <= x && a[n+i+1] <= x) || (a[n-i] <= x && a[n-i-1] <= x)) return true;
		if ((a[n+i] > x && a[n+i+1] > x) || (a[n-i] > x && a[n-i-1] > x)) return false;
	}
	return a[1] <= x;
}

int main() {
	scanf("%d", &n);
	for (register int i = 1; i < 2*n; i++)
		scanf("%d", a+i);
	int L = 0, R = 2*n-1;
	while (L < R) {
		int mid = (L+R)>>1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	printf("%d", L);
	return 0;
}