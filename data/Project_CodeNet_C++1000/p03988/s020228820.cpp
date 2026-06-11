//
// main.cpp
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
	ll N;
	cin >> N;
	vector<ll> as(N);
	rep(i,0,N) {
		cin >> as[i];
	}
	sort(as.rbegin(), as.rend());
	unordered_map<ll,ll> hist;
	rep(i,0,N) {
		hist[as[i]]++;
	}
	ll max = as[0];
	ll min = as[0] - as[0] / 2;
	if (as[as.size()-1] != min) {
		cout << "Impossible" << endl;
		return 0;	
	}
	if (hist[max] < 2) {
		cout << "Impossible" << endl;
		return 0;	
	}
	if (max % 2 == 1) {
		if (hist[min] != 2) {
			cout << "Impossible" << endl;
			return 0;	
		}
	} else {
		if (hist[min] != 1) {
			cout << "Impossible" << endl;
			return 0;	
		}	
	}
	rep(x,min+1,max) {
		if (hist[x] < 2) {
			cout << "Impossible" << endl;
			return 0;	
		}
	}
	cout << "Possible" << endl;
	return 0;	
}
