#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n;
	cin >> n;
	vector<int64_t> a(n * 3);
	for (int i = 0; i < n * 3; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	int64_t ans = 0;
	for (int i = n; i < n * 3; i = i + 2) {
		ans += a.at(i);
	}
	cout << ans << endl;
}