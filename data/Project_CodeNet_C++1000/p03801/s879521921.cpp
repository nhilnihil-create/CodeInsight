//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
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
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
	ll N;
	cin >> N;
	vector<ll> Ais(N);
	rep(i,0,N) {
		cin >> Ais[i];
	}
	vector<ll> max_idx(N, 0);
	rep(i,1,N) {
		if (Ais[i] <= Ais[max_idx[i-1]]) {
			max_idx[i] = max_idx[i-1];
		} else {
			max_idx[i] = i;
		}
	}
	struct Stones {
		ll idx;
		ll Ai;
	};
	vector<Stones> sorted;
	rep(i,0,N) {
		sorted.push_back({i, Ais[i]});
	}
	sort(sorted.begin(), sorted.end(), [](Stones lhs, Stones rhs){ 
		return lhs.Ai < rhs.Ai || (lhs.Ai == rhs.Ai && lhs.idx < rhs.idx);
	});
	vector<ll> idx_map(N);
	rep(i,0,N) {
		idx_map[sorted[i].idx] = i;
	}
	vector<ll> sum_sorted(N+1);
	rep(n,1,N+1) {
		sum_sorted[n] += sum_sorted[n-1] + sorted[N-n].Ai;
	}
	vector<ll> sum_above(N);
	rep(idx,0,N) {
		ll sorted_idx = idx_map[idx];
		ll Ai = Ais[idx];
		sum_above[idx] = sum_sorted[N-sorted_idx] - (N-sorted_idx) * Ai;
	}
	ll sum = sum_sorted[N];
	vector<ll> ans(N);
	ll idx = max_idx[N-1];
	while (true) {
		if (idx == 0) {
			ans[idx] = sum - sum_above[0];
			break;
		}
		ll next_idx = max_idx[idx-1];
		ans[idx] = sum_above[next_idx] - sum_above[idx];
		idx = next_idx;
	}
	rep(i,0,N) {
		cout << ans[i] << endl;
	}
}
