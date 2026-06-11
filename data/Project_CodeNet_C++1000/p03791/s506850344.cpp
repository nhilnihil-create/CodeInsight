#include <cstdio>
const int mod = 1000000007;
int n, a[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ret = 1, ptr = 0;
	for (int i = 0; i < n; i++) {
		while (ptr < n && a[ptr] > (ptr - i) * 2) ptr++;
		if (ptr < n && a[ptr] == (ptr - i) * 2) ptr++;
		ret = 1LL * ret * (ptr - i) % mod;
	}
	printf("%d\n", ret);
	return 0;
}