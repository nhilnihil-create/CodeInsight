#include <bits/stdc++.h>
#define N 200010
using namespace std;
int ____, a[N], b[N];
bool S(int i, int j, int k) {
	return a[i] <= k && a[j] <= k;
}
bool B(int i, int j, int k) {
	return a[i] > k && a[j] > k; 
}
int chk(int k) {
	for (int i = 0; i < ____ - 1; ++i) {
		if (B(____ + i, ____ + i + 1, k) || B(____ - i, ____ - i - 1, k)) return 0;
		if (S(____ + i, ____ + i + 1, k) || S(____ - i, ____ - i - 1, k)) return 1;
	}
	return S(1, 1, ____);
}
int main() {
	scanf("%d", &____);
	for (int i = 1; i <= 2 * ____ - 1; ++i) scanf("%d", &a[i]);
	int l = 1, r = 2 * ____ - 1, ans = 0;
	for (; l < r; ) {
		int mid = (l + r) / 2;
		if (chk(mid)) {
			r = mid;
		} else l = mid + 1;
	}
	printf("%d", r);
	return 0;
}
