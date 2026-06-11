#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = (int)(s.size() + t.size());
	rep(i, n) {
		bool ok = true;
		rep(j, n - i) {
			if (s[i + j] != t[j]) ok = false;
		}
		if (ok) {
			ans = 2 * i + (n - i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}