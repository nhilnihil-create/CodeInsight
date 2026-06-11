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

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	vector<vector<ll>> binom_table;
	binom_table.push_back({});
	binom_table.back().push_back(1);
	for (ll n = 1; n <= N; n++) {
		binom_table.push_back({});
		for (ll r = 0; r <= N; r++) {
			auto b = [&binom_table](ll n, ll r) {
				if (0 <= r && r <= n) {
					return binom_table[n][r];
				} else {
					return (ll)0;
				}
			};
			binom_table.back().push_back(b(n-1, r-1)+b(n-1, r));
		}
	}
	vector<ll> vis(N);
	for (int i = 0; i < N; i++) {
		cin >> vis[i];
	}
	sort(vis.rbegin(), vis.rend());
	ll sum = 0;
	ll max_cnt = 0;
	ll min_cnt = 0;
	ll min_cnt_A = 0;
	for (ll i = 0; i < N; i++) {
		if (i < A) {
			sum += vis[i];
		}
		if (vis[i] == vis[0]) {
			max_cnt++;
		}
		if (vis[i] == vis[A-1]) {
			min_cnt++;
			if (i < A) {
				min_cnt_A++;
			}
		}
	}
	cout << fixed << setprecision(10) << (double)sum/(double)A << endl;
	if (max_cnt < A) {
		cout << binom_table[min_cnt][min_cnt_A] << endl;
	} else {
		B = min(B, max_cnt);
		ll cases = 0;
		for (ll n = A; n <= B; n++) {
			cases += binom_table[max_cnt][n];
		}
		cout << cases << endl;
	}
}
