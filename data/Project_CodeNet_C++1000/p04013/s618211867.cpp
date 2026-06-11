#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 55;

int a[N], x, dp[N][N][N * N];

int f(int idx, int cnt, int val) {
	if(idx == 0) {
		if(cnt) return x * cnt ==  val;
		return 0;
	}
	if(~dp[idx][cnt][val]) return dp[idx][cnt][val];
	return dp[idx][cnt][val] = f(idx - 1, cnt, val) + f(idx - 1, cnt + 1, val + a[idx]);

}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n >> x;
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << f(n, 0, 0) << endl;
}