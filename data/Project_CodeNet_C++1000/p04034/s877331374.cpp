#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int>dp1(n);
	vector<bool>dp2(n);
	dp2[0] = true;
	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		dp2[i] = false;;
	}
	for (int i = 0; i < k; i++) {
		int fro, to;
		cin >> fro >> to;
		fro--, to--;
		if (dp2[fro]) {
			dp2[to] = true;
		}
		dp1[to]++;
		dp1[fro]--;
		if (dp1[fro] == 0) {
			dp2[fro] = false;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp2[i] > 0)ans++;
	}
	cout << ans << endl;
}

