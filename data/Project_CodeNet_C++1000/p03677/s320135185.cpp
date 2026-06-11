#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;


constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
	template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
	template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
	template<typename T> void chadd(T& a, T b) { a = a + b; }

	void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

	void CCout(long long x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const T& x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cerr << x[i] << (i == sz - 1 ? end : sep); } }

	// 標準入出力
	struct inp {
		std::size_t sz;
		inp(std::size_t _sz = 1) : sz(_sz) {}
		template <typename T> operator T () const { T a; std::cin >> a; return a; }
		template <typename T> operator std::vector<T>() const { vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
		template <typename T, typename U> operator std::pair<T, U>() const { T f; U s; std::cin >> f >> s; return std::pair<T, U>(f, s); }
	};

	inp inp1; // input one
}

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> a = inp(n);
	rep(i, n) --a[i];


	// O(nm)なら余裕

	// すげー
	// x = i のときがわかったら x = i + 1 のときも簡単に計算できる
	ll tmp = 0;
	rep(i, n - 1) {
		int normal = (a[i + 1] - a[i] + m) % m;
		int warp = (a[i + 1] - 0 + m) % m + 1;
		tmp += min(normal, warp);
	}

	// これをもとに x = 1, 2, 3, ... のときも求める
	// imos法でxがa[i]とa[i + 1]の間(両端覗く)にあるか求める
	vector<int> num(m, 0);
	rep(i, n - 1) {
		// 隣り合っているときはなにもいない これいらなそう
		if ((a[i + 1] - a[i] + m) % m == 1) continue;

		int from = (a[i] + 1) % m;
		int to = a[i + 1];

		if (to > from) {
			// 0をまたがっていないとき
			++num[from];
			--num[to];
		}
		else {
			++num[0];
			++num[from];
			--num[to];
		}
	}

	size_t s = (a[0] + 1) % m;
	CCout(num);
	rep(i, m - 1) {
		num[i + 1] += num[i];
	}
	vector<vector<int>> point(m, vector<int>());
	Rep(i, 1, n) {
		point[a[i]].emplace_back(i); // インデックスを保存
	}

	CCout(num);

	ll ans = tmp;

	Rep(x, 1, m) {
		ll tmp_ans = tmp;
		rep(i, point[x - 1].size()) {
			// x - 1 と目的地が被っていたインデックス
			// ワープ使わんほうがはやくなる
			int j = point[x - 1][i];
			tmp_ans += (a[j] - a[j - 1] + m) % m - 1;
		}
		// xがa[i]とa[i + 1]の間にある分だけ引く
		tmp_ans -= num[x - 1];

		cerr << x << " " << tmp_ans << endl;
		chmin(ans, tmp_ans);
		tmp = tmp_ans;
	}

	Cout(ans);

	// 神！ きたでしょ

	return 0;
}
