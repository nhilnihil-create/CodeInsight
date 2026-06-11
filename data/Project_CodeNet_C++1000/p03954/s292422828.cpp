#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], b[N], c[N];

inline int check(int x) {
	for (int i = 1; i <= n; ++i)	c[i] = a[i] >= x;
	int mid = 1 + n >> 1, l = mid, r = mid, res = c[mid];
	c[0] = c[1];
	for (; l >= 1 && c[l - 1] != c[l] && c[r + 1] != c[r]; --l, ++r)	res ^= 1;
	return res;
}

inline int solve() {
	int l = 1, r = n, res;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(b[mid]))	l = mid + 1, res = mid;
		else r = mid - 1;
	}
	return b[res];
}

int main() {
	
	scanf("%d", &n);
	n = n * 2 - 1;
	for (int i = 1; i <= n; ++i)	scanf("%d", a + i);
	for (int i = 1; i <= n; ++i)	b[i] = a[i];
	
	sort(b + 1, b + n + 1);
	
	printf("%d\n", solve());	
	
	return 0;
}
