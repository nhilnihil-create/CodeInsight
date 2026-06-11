#include <bits/stdc++.h>
using namespace std;

const pair<int, int> vod = {1000000007, 1000000009};

void gns(int &a, int mod) {
	if(a > mod) a -= mod;
	if(a < 0) a += mod;
}

struct vint {
	pair<int, int> vum;

	void add(vint v) {
		vum.first += v.vum.first;
		vum.second += v.vum.second;
		gns(vum.first, vod.first);
		gns(vum.second, vod.second);
	}

	void sub(vint v) {
		vum.first -= v.vum.first;
		vum.second -= v.vum.second;
		gns(vum.first, vod.first);
		gns(vum.second, vod.second);
	}

	bool is0() {
		return (vum.first == 0 && vum.second == 0);
	}
};

const int N = 5003, K = 5003;
int n, k, a[N];
vint dp[K];

bool aa0(int a) {
	for(int i = a; i < k; ++i) {
		if(!dp[i].is0())
			return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp[0].vum.first = dp[0].vum.second = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = k - 1; j >= a[i]; --j) {
			dp[j].add(dp[j - a[i]]);
		}
	}
	int fp = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] >= k) continue;
		for(int j = a[i]; j < k; ++j) {
			dp[j].sub(dp[j - a[i]]);
		}
		fp += aa0(k - a[i]);
		for(int j = k - 1; j >= a[i]; --j) {
			dp[j].add(dp[j - a[i]]);
		}
	}
	cout << fp << endl;
	return 0;
}
