#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int64_t ans; cin >> ans; --ans;
	int64_t maxi = 1;
	for(int i = 1; i < n; ++i) {
		int64_t a; cin >> a;
		if(a <= maxi + 1) {
			maxi = max(maxi, a);
			cerr << a << " " << ans << '\n';
			continue;
		}
		ans += (a - 1) / (maxi + 1);
	}
	cout << ans << '\n';
	return 0;
}
