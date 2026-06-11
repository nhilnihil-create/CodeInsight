//
// main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

int main() {
	ll H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H % h == 0 && W % w == 0) {
		cout << "No" << endl;
		return 0;
	}
	bool swapped = false;
	if (W % w == 0) {
		swap(H, W);
		swap(h, w);
		swapped = true;
	}
	auto ans = make_vec_nd((ll)0, W, H);
	ll large = 1000000000;
	rep(y,0,H) {
		rep(x,0,W) {
			if (x % w == 0) {
				ans[x][y] = large - 1;
			} else if (x % w == w - 1) {
				ans[x][y] = -large;
			} else {
				ans[x][y] = 0;
			}
		}
	}
	if (swapped) {
		auto ans0 = ans;
		ans = make_vec_nd((ll)0, H, W);
		rep(y,0,H) {
			rep(x,0,W) {
				ans[y][x] = ans0[x][y];
			}
		}
		swap(W, H);
		swap(w, h);
	}
	cout << "Yes" << endl;
	rep(y,0,H) {
		rep(x,0,W) {
			cout << ans[x][y];
			if (x != W-1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
