#include <cstdio>
 
const int maxn = 2e5;
int n, a[maxn + 3];
 
bool check(int x) {
	for (int i = 0; i <= n - 1; i++) {
		if ((a[n - i] < x && a[n - i - 1] < x) || (a[n + i] < x && a[n + i + 1] < x)) {
			return false;
		}
		if ((a[n - i] >= x && a[n - i - 1] >= x) || (a[n + i] >= x && a[n + i + 1] >= x)) {
			return true;
		}
	}
	return a[1] >= x;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; i++) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = 2 * n - 1, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", l);
	return 0;
}