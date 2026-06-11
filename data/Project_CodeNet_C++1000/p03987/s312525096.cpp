#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr ll MAX = 800000;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<ll, ll>> a;
	rep(i, 0, n) {
		ll b;
		cin >> b;
		a.emplace_back(b, i + 1);
	}
	sort(a.begin(), a.end());

	// 自分C
	// 自分よりデカい奴がいる左L
	// 自分よりデカい奴がいる右R
	// (R - C) * (C - L)回コイツは選ばれる
	ll ans = 0;
	set<ll> ids;
	ids.insert(0);
	ids.insert((ll)n + 1);
	rep(i, 0, n) {
		ll val = a[i].first;
		ll idx = a[i].second;
		// この時、自分よりデカい奴のインデックスが保存されてる
		ids.insert(idx);
		auto itr = ids.find(idx);
		int L = *--itr;
		int R = *++++itr;
		ans += (R - idx) * (idx - L) * val;
	}
	cout << ans << endl;
	return 0;

}
