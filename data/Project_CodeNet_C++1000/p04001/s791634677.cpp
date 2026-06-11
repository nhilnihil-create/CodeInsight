#include <bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str; int n = str.size();
	int ans = 0;
	for(int i = 0; i < (1 << (n - 1)); i++) {
		int cur = 0;
		for(int j = 0; j < n; j++) {
			cur = cur * 10 + (str[j] - '0');
			if((i >> j) & 1) {
				ans += cur;
				cur = 0;
			}
		}
		ans += cur;
	}

	cout << ans << endl;
}