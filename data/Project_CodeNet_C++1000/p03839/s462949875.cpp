//
//  main.cpp
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
	ll N, K;
	cin >> N >> K;
	vector<ll> Ais(N);
	rep(i,0,N) {
		cin >> Ais[i];
	}
	vector<ll> sum(N+1);
	rep(n,1,N+1) {
		sum[n] = sum[n-1] + Ais[n-1];
	}
	vector<ll> pos_sum(N+1);
	rep(n,1,N+1) {
		pos_sum[n] = pos_sum[n-1] + max((ll)0, Ais[n-1]);
	}
	ll ans = numeric_limits<ll>::min();
	rep(i,0,N-K+1) {
		ll ans_loc = pos_sum[i] + (pos_sum[N] - pos_sum[i+K]) + max((ll)0, sum[i+K]-sum[i]);
		ans = max(ans, ans_loc);
	}
	cout << ans << endl;
}
