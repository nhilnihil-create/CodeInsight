#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;
int a[100000];
int cnt[100000];
LL sum[100000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] < a[i + 1]) {
			if (a[i] + 1 < m) cnt[a[i] + 1]++;
			 cnt[a[i + 1]]--;
		}
		else {
			if (a[i] + 1 < m) cnt[a[i] + 1]++;
			cnt[0]++;
			cnt[a[i + 1]]--;
		}
		sum[a[i + 1]] += (a[i + 1] - a[i] + m) % m - 1;
	}
	for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
	LL now = 0;
	for (int i = 0; i + 1 < n; i++) {
		now += min((a[i + 1] - a[i] + m) % m, a[i + 1] + 1);
	}
	LL ans = now;
	for (int i = 0; i + 1 < m; i++) {
		now += sum[i];
		now -= cnt[i];
		ans = min(ans, now);
	}
	cout << ans << endl;
}