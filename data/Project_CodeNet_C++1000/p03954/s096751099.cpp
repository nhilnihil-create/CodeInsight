#include <bits/stdc++.h>

const int MAXN = 200010;
int n, A[MAXN], B[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; int m = n * 2 - 1;
	for (int i = 1; i <= m; ++i) std::cin >> A[i];
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		for (int i = 1; i <= m; ++i) B[i] = A[i] <= mid;
		int fir = -1;
		for (int i = 0; i + 1 < n; ++i) {
			if (B[n + i] == B[n + i + 1]) { fir = n + i; break; }
			if (B[n - i] == B[n - i - 1]) { fir = n - i - 1; break; }
		}
		bool can = false;
		if (fir != -1) can = B[fir] == 1;
		else can = B[n] ^ (n - 1 & 1) == 1;
		if (can) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	std::cout << ans << std::endl;
	return 0;
}
