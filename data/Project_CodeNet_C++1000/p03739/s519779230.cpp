
// C - Sequence

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int a[100000];
ll cum1[100000];
ll cum2[100000];

int main() {
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	// 偶数項を正にする場合
	ll ans1 = 0;
	if (a[0] > 0) {
		cum1[0] = a[0];
	} else {
		ans1 += abs(a[0]) + 1;
		cum1[0] = 1;
	}

	for (int i=1; i<n; i++) {
		if (i % 2 == 0) {
			if (cum1[i-1] + a[i] > 0) {
				cum1[i] = cum1[i-1] + a[i];
			} else {
				ans1 += abs(cum1[i-1] + a[i]) + 1;
				cum1[i] = 1;
			}
		} else {
			if (cum1[i-1] + a[i] < 0) {
				cum1[i] = cum1[i-1] + a[i];
			} else {
				ans1 += abs(cum1[i-1] + a[i]) + 1;
				cum1[i] = -1;
			}
		}
	}

	// 偶数項を負にする場合
	ll ans2 = 0;
	if (a[0] < 0) {
		cum2[0] = a[0];
	} else {
		ans2 += abs(a[0]) + 1;
		cum2[0] = -1;
	}

	for (int i=1; i<n; i++) {
		if (i % 2 == 0) {
			if (cum2[i-1] + a[i] < 0) {
				cum2[i] = cum2[i-1] + a[i];
			} else {
				ans2 += abs(cum2[i-1] + a[i]) + 1;
				cum2[i] = -1;
			}
		} else {
			if (cum2[i-1] + a[i] > 0) {
				cum2[i] = cum2[i-1] + a[i];
			} else {
				ans2 += abs(cum2[i-1] + a[i]) + 1;
				cum2[i] = 1;
			}
		}
	}

	ll ans = min(ans1, ans2);

	cout << ans << endl;

	return 0;
}