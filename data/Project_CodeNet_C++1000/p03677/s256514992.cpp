#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll a[100000];
ll sum[100000];
ll cnt[100000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i + 1 < n; i++) {
		sum[a[i + 1]] += (a[i + 1] + m - a[i]) % m - 1;
		if (a[i] < a[i + 1]) {
			cnt[a[i] + 1]++;
			cnt[a[i + 1]]--;
		}
		else {
			if (a[i] + 1 < m) cnt[a[i] + 1]++;
			cnt[0]++;
			cnt[a[i + 1]]--;
		}
	}
	for (int i = 0; i + 1 < m; i++) cnt[i + 1] += cnt[i];
	ll now = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] < a[i + 1]) now += a[i + 1] - a[i];
		else now += a[i + 1] + 1;
	}
	ll ans = now;
	for (int i = 0; i + 1 < m; i++) {
		now += sum[i];
		now -= cnt[i];
		ans = min(ans, now);
	}
	cout << ans << endl;
 }