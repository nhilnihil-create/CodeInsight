#include <bits/stdc++.h>
#define SZ(v) ((int)((v).size()))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n+1);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] & 1) { --a[i]; if (a[i+1]) ++a[i+1]; }
		res += a[i];
	}
	cout << res/2 << "\n";
}
