#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int pass = 0, rank = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'c') {
			cout << "No\n";
		} else if (s[i] == 'a') {
			if (pass < a + b) {
				pass++;
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			if (pass < a + b && rank < b) {
				pass++;
				rank++;
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
