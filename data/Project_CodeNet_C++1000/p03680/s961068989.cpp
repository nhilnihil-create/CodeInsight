#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;

	int ans = 0, now = 0;
	while (true) {
		if (ans >= n) {
			cout << -1 << endl;
			return 0;
		}
		if (now == 1) {
			cout << ans << endl;
			return 0;
		}
		now = a[now]-1;
		ans++;
	}

	return 0;
}