//
// main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
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
	ll N, K;
	cin >> N >> K;
	vector<ll> As(N);
	rep(i,0,N) {
		cin >> As[i];
	}
	unordered_set<ll> now;
	now.insert(0);
	vector<unordered_set<ll>> dpr(N);
	rrep(i,N,0) {
		unordered_set<ll> now0;
		for (ll x : now) {
			ll next = x + As[i];
			if (next < K && now.find(next) == now.end()) {
				dpr[i].insert(next);
				now0.insert(next);
			}
		}
		if (now0.size() > now.size()) {
			swap(now, now0);
		}
		for (ll x : now0) {
			now.insert(x);
		}
	}
	set<ll> right(now.begin(), now.end());
	unordered_set<ll> left;
	left.insert(0);
	ll need = 0;
	rep(i,0,N) {
		for (ll x : dpr[i]) {
			right.erase(x);
		}
		if (As[i] >= K) {
			need++;
		} else {
			for(ll l : left) {
				if (right.lower_bound(K-As[i]-l) != right.lower_bound(K-l)) {
					need++;
					break;
				}
			}
		}
		unordered_set<ll> left0;
		for (ll x : left) {
			ll next = x + As[i];
			if (next < K) {
				left0.insert(next);
			}
		}
		if (left0.size() > left.size()) {
			swap(left0, left);
		}
		for (ll x : left0) {
			left.insert(x);
		}
	}
	cout << N - need << endl;
}
