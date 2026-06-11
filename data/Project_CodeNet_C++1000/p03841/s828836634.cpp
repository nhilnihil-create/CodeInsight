#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;


void solve() {
	int n; cin >> n;
	pair<int, int> x[500]; rep(i, n) { x[i].second = i + 1; cin >> x[i].first; }
	sort(x, x + n);

	vector<int> buf;
	buf.resize(n*n);
	size_t p = 0;
	rep(i, n) {
		int k = x[i].second;
		size_t kp = x[i].first - 1;
		for (int j = 0; j < k - 1; j++) {
			for (; buf[p] != 0; p++) {
				if (p == kp) {
					cout << "No" << endl; return;
				}
			}
			buf[p] = k;
		}
		buf[kp] = k;
	}
	rep(i, n) {
		int k = x[i].second;
		size_t kp = x[i].first - 1;
		for (int j = 0; j < n - k; j++) {
			for (; buf[p] != 0; p++) {}
			if (p < kp) {
				cout << "No" << endl; return;
			}
			buf[p] = k;
		}
	}

	cout << "Yes" << endl;
	rep(i, buf.size()) {
		if (i != 0) cout << " ";
		cout << buf[i];
	}
}

int main() {

	solve();

	return 0;
}
