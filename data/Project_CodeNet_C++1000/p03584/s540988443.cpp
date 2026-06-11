//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
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
	ll N, K;
	cin >> N >> K;
	struct Number {
		ll A;
		ll B;
	};
	vector<Number> numbers(N);
	for (ll i = 0; i < N; i++) {
		cin >> numbers[i].A >> numbers[i].B;
	}
	vector<ll> masks;
	masks.push_back(K);
	for (ll i = 0; i < 32; i++) {
		if ((K & ((ll)1 << i)) != 0) {
			ll mask = K;
			mask &= ~((ll)1 << i);
			mask |= (((ll)1 << i) - 1);
			masks.push_back(mask);
		}
	}
	ll ans = numeric_limits<ll>::min();
	for (ll mask : masks) {
		ll sum = 0;
		for (Number num : numbers) {
			if ((num.A & (~mask)) == 0) {
				sum += num.B;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
