#include <bits/stdc++.h>
#define N (int)1e6+5
using namespace std;
int n, a, b;
int h[N];
bool check(int x) {
	int dis = a - b;
	int mns = b * x;
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		int tmp = h[i] - mns;
		if (tmp <= 0) continue;
		cnt += (tmp + dis - 1) / dis;
		if (cnt > x) return false;
//		cout << i << " " << tmp << " " << cnt << endl;
	}
	return cnt <= x;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	int mx = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &h[i]);
		mx = max(mx, h[i]);
	}
	int l = 1, r = (mx+b-1) / b, ans;
	while (l <= r) {
		int mid = ((l - r) >> 1) + r;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
//		cout << mid << " " << ans << " " << check(mid) << endl;
	}
	printf("%d", ans);
	return 0;
}