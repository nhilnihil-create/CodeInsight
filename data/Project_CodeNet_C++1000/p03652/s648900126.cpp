//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
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

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

vector<vector<ll>> Ais;
ll N, M;

bool can_leq(ll C) {
	vector<bool> forbidden(M);
	vector<ll> most_like_idx(N);
	ll forbid_cnt = 0;
	while (forbid_cnt < M) {
		vector<ll> liked_cnt(M);
		for (ll person = 0; person < N; person++) {
			while (forbidden[Ais[person][most_like_idx[person]]]) {
				most_like_idx[person]++;
			}
			liked_cnt[Ais[person][most_like_idx[person]]]++;
		}
		auto max_it = max_element(liked_cnt.begin(), liked_cnt.end());
		if (*max_it <= C) {
			return true;
		}
		forbidden[distance(liked_cnt.begin(), max_it)] = true;
		forbid_cnt++;
	}
	return false;
}

int main() {
	cin >> N >> M;
	Ais = make_vec_nd((ll)0, N, M);
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> Ais[i][j];
			Ais[i][j]--;
		}
	}
	ll lower = 0;
	ll upper = N;
	while (upper - lower >= 2) {
		ll half = (lower + upper) / 2;
		if (can_leq(half)) {
			upper = half;
		} else {
			lower = half;
		}
	}
	cout << upper << endl;
}
