#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

int arr[205];
LL n;

int main() {
	scanf("%lld", &n); ++n;
	int he = 100, ta = 99, tn = 0, c = 0;
	for (LL i = n; i; i >>= 1) ++tn;
	for (int i = tn - 2; i >= 0; i--) {
		arr[++ta] = ++c;
		if (n >> i & 1) arr[--he] = ++c;
	}
	printf("%d\n", c << 1);
	for (int i = he; i <= ta; i++) printf("%d ", arr[i]);
	for (int i = 1; i <= c; i++) printf("%d ", i);
	return 0;
}