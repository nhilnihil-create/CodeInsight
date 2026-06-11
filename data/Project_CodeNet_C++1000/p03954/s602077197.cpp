#include <bits/stdc++.h>
using namespace std;
#define N 100010
int num[N * 2], n, del[N * 2];
inline bool check(int mid) {
	for (int i = 1;i < n * 2 - 1;i++) del[i] = (num[i] >= mid) == (num[i + 1] >= mid);
	for (int i = 1;i < n;i++) {
		if (del[n + i - 1]) return num[n + i - 1] >= mid;
		if (del[n - i]) return num[n - i] >= mid;
	}
	return num[1] >= mid;
}
int main() {
	scanf("%d", &n);
	for (int i = 1;i < n * 2;i++) scanf("%d", &num[i]);
	int l = 1, r = 2 * n - 1, mid, ans = -1;
	while (l <= r) 
		if (check(mid = (l + r) >> 1)) ans = mid, l = mid + 1;
		else r = mid - 1;
	printf("%d\n", ans);
}