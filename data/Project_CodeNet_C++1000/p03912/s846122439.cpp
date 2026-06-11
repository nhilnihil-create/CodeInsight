#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <numeric>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	int x;
	unordered_map<int, int> cnt;
	vector<vector<int>> num(100001);
	rep(i, 0, n) {
		cin >> x;
		cnt[x]++;
	}
	for (auto e : cnt)
		num[e.first % m].push_back(e.second);

	int ans = 0;

	rep(i, 0, m / 2 + 1) {
		int k = (m - i) % m;
		int a = accumulate(num[i].begin(), num[i].end(), 0);
		int b = accumulate(num[k].begin(), num[k].end(), 0);
		if (i == k) {
			ans += a / 2;
			continue;
		}
		sort(num[i].begin(), num[i].end());
		sort(num[k].begin(), num[k].end());
		ans += min(a, b);
		if (a > b) {
			swap(num[i], num[k]);
			swap(a, b);
		}

		// 同じ数が奇数個では少なくとも一つはあぶれる
		int t = a;
		rep(j, 0, (int)num[k].size()) {
			t -= num[k][j] & 1;
			num[k][j] -= num[k][j] & 1;
			t = max(t, 0);
		}

		int j = 0;
		while (j < (int)num[k].size()) {
			int d = min(num[k][j], t);
			t -= d;
			num[k][j] -= d;
			if (t == 0)
				ans += num[k][j] / 2;
			++j;
		}
	}
	cout << ans << endl;

	return 0;
}
