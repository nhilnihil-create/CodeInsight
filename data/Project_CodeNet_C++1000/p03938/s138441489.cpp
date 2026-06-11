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
	ll N;
	cin >> N;
	vector<ll> pis;
	vector<ll> qis(N);
	for (ll i = 0; i < N; i++) {
		ll pi;
		cin >> pi;
		pi--;
		pis.push_back(pi);
		qis[pi] = i;
	}
	vector<ll> ais(N);
	vector<ll> bis(N);
	vector<ll> cis(N);
	for (ll i = 0; i < N; i++) {
		cis[i] = i;
	}
	for (ll i = 1; i < N; i++) {
		ais[i] = max(ais[i-1], ais[i-1] - cis[qis[i-1]] + cis[qis[i]]) + 1;
	}
	for (ll i = 0; i < N; i++) {
		bis[i] = cis[qis[i]] - ais[i];
	}
	for (vector<ll>* xs_p : {&ais, &bis}) {
		vector<ll>& xs = *xs_p;
		ll mn = *min_element(xs.begin(), xs.end());
		if (mn <= 0) {
			for (ll i = 0; i < xs.size(); i++) {
				xs[i] += -mn + 1;
			}
		}
		for (ll i = 0; i < xs.size(); i++) {
			cout << xs[i];
			if (i < xs.size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
