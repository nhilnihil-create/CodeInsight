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
	ll ai, ao, at, aj, al, as, az;
	cin >> ai >> ao >> at >> aj >> al >> as >> az;
	ll ans = 0;
	ans += ao;
	if (ai == 0 || aj == 0 || al == 0) {
		ans += 2 * (ai / 2) + 2 * (aj / 2) + 2 * (al / 2);
	} else {
		ans += max(3 + 2 * ((ai-1)/2) + 2 * ((aj-1)/2) + 2 * ((al-1)/2),
				       2 * (ai / 2)   + 2 * (aj / 2)   + 2 * (al / 2));
	}
	cout << ans << endl;
}
