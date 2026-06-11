#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5;

int n;
ll dp[N], k, ans;
vector <ll> seg[N << 2];

void build(int id = 1, int b = 0, int e = n + 1) {
	if(e - b == 1) {
		seg[id].push_back(dp[b]);
		return;
	}
	int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
	build(lc, b, mid);
	build(rc, mid, e);
	for (int i = 0; i < seg[lc].size(); i++)
		seg[id].push_back(seg[lc][i]);
	for (int i = 0; i < seg[rc].size(); i++)
		seg[id].push_back(seg[rc][i]);
	sort(seg[id].begin(), seg[id].end());
}

ll get(int l, int r, ll val, int id = 1, int b = 0, int e = n + 1) {
	if(l >= e || b >= r)
		return 0;
	if(l <= b && e <= r) {
		int x = lower_bound(seg[id].begin(), seg[id].end(), val) - seg[id].begin();
		int sz = seg[id].size();
		return sz - x;
	}
	int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
	return get(l, r, val, lc, b, mid) + get(l, r, val, rc, mid, e);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> dp[i + 1];
		dp[i + 1] += dp[i] - k;
	}
	build();
	for (int i = 0; i <= n; i++) {
		ans += get(i + 1, n + 1, dp[i]);
	}
	cout << ans << "\n";
}
