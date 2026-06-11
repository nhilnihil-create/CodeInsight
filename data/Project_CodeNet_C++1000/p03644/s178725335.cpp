#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {

	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	int ans = 0;
	int maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		int x = i;
		int cnt = 0;
		while (true) {
			if (x % 2 == 1) break;
			if (x / 2 == 0) {
				break;
			}
			else {
				x /= 2;
			}
			cnt++;
		}
		if (chmax(maxCnt, cnt)) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}