#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans1 = 0;
	ll sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += a[i];
		if (i % 2 == 0) {
			if (0 < sum1) {}
			else if (sum1 < 0) {
				ans1 += -1 * sum1 + 1;
				sum1 = 1;
			}
			else { // sum1 == 0
				sum1 += 1;
				ans1 += 1;
			}
		}
		else { // i % 2 != 0
			if (0 < sum1) {
				ans1 += sum1 + 1;
				sum1 = -1;
			
			}
			else if (sum1 < 0) {}
			else { // sum1 == 0
				sum1 += -1;
				ans1 += 1;
			}
		}
	}
	ll ans2 = 0;
	ll sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum2 += a[i];
		if (i % 2 != 0) {
			if (0 < sum2) {}
			else if (sum2 < 0) {
				ans2 += -1 * sum2 + 1;
				sum2 = 1;
			}
			else { // sum1 == 0
				sum2 += 1;
				ans2 += 1;
			}
		}
		else { // i % 2 == 0
			if (0 < sum2) {
				ans2 += sum2 + 1;
				sum2 = -1;

			}
			else if (sum2 < 0) {}
			else { // sum2 == 0
				sum2 += -1;
				ans2 += 1;
			}
		}
	}
	cout << min(ans1, ans2) << endl;
    return 0;
}