#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 10;

int n, m, a[N * 2], b[N * 2];

int check(int mid) {
	int dis = 0x3f3f3f3f;
	for (int i = 1; i <= n * 2 - 1; ++i)
		b[i] = (a[i] >= mid);
	int ans = b[1];
	for (int i = 1; i < n * 2 - 1; ++i) {
		if (b[i] == b[i + 1]) {
			int d = min(abs(n - i), abs(n - i - 1));
			if (d < dis) {
				dis = d;
				ans = b[i];
			}
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n * 2 - 1; ++i)
		scanf("%d", &a[i]);
	int l = 1, r = 2 * n - 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
