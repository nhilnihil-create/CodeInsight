#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N];
bool t;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	while (1) {
		bool sum = 0;
		for (int i = 0; i < n; ++i) {
			sum ^= (a[i] - 1) & 1;
		}
		if (sum) {
			if (!t) cout << "First";
			else cout << "Second";
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += a[i] & 1;
		}
		int cnt1 = 0;
		for (int i = 0; i < n; ++i) {
			cnt1 += a[i] == 1;
		}
		if (cnt == 1 && !cnt1) {
			int gcd = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] & 1) a[i]--;
				gcd = __gcd(gcd, a[i]);
			}
			for (int i = 0; i < n; ++i) {
				a[i] /= gcd;
			}
		}
		else {
			t ^= 1;
			if (!t) cout << "First";
			else cout << "Second";
			return 0;
		}
		t ^= 1;	
	}
}