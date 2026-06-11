#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
int main() {
	i64 n; cin >> n;
	vector<pair<i64, i64>> a;
	rep(i, 1, n + 1) {
		int t;
		cin >> t;
		a.emplace_back(t, i);
	}

	// 小さいほう/大きいほうから埋めていって考える状態数を減らすのは常套手段ですよね！
	sort(a.begin(), a.end());

	set<i64> ids;
	ids.insert(0);
	ids.insert(n + 1);
	i64 ans = 0;
	rep(i, 0, n) {
		i64 val = a[i].first;
		i64 idx = a[i].second;
		ids.insert(idx);
		auto itr = ids.find(idx);
		ans += val * (idx - *--itr) * (*++++itr - idx);
	}
	cout << ans << '\n';
	return 0;
}