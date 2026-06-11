#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int n, a[maxn];
int S(int i, int j, int k) {return a[i] <= k && a[j] <= k;}
int M(int i, int j, int k) {return a[i] > k && a[j] > k;}
int check(int k) {
	for (int i = 0; i < n - 1; ++i) {
		if(M(n + i, n + i + 1, k) || M(n - i, n - i - 1, k)) return 0;
		if(S(n + i, n + i + 1, k) || S(n - i, n - i - 1, k)) return 1;
	}
	return S(1, 1, k);
} 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; ++i) scanf("%d", &a[i]);
	int ans, l = 1, r = 2 * n - 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}