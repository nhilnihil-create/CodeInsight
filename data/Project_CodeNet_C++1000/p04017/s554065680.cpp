#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(n); for(int i = 0; i < n; ++i) cin >> x[i];
	int l; cin >> l;
	// dp[i][k] := iから2^kで行ける最大
	vector<vector<int>> dpL(n, vector<int>(21));
	vector<vector<int>> dpR(n, vector<int>(21));
	for(int i = 0; i < n; ++i) {
		dpL[i][0] = lower_bound(x.begin(), x.end(), x[i] - l) - x.begin();
		dpR[i][0] = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
	}
	for(int k = 0; k < 20; ++k) {
		for(int i = 0; i < n; ++i) {
			dpL[i][k + 1] = dpL[dpL[i][k]][k];
			dpR[i][k + 1] = dpR[dpR[i][k]][k];
		}
	}
	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		--a; --b;
		int ans = 0;
		int now = a;
		if(a < b) {
			for(int k = 20; k >= 0; --k) {
				if(dpR[now][k] < b) {
					now = dpR[now][k];
					ans += (1 << k);
				}
			}
		} else {
			for(int k = 20; k >= 0; --k) {
				if(b < dpL[now][k]) {
					now = dpL[now][k];
					ans += (1 << k);
				}
			}
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}