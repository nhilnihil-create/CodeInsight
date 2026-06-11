//
//  main.cpp
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <math.h>
#include <queue>
#include <tuple>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "string.h"
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <set>
#include <memory>
#include <exception>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

#define rep(i,a,b) for(ll i=a;i<b;i++)

int main() {
	ll N;
	cin >> N;
	vector<ll> ais(N);
	rep(i,0,N) {
		cin >> ais[i];
	}
	vector<ll> sorted = ais;
	sort(sorted.begin(), sorted.end());
	unordered_map<ll, ll> map;
	rep(i,0,N) {
		map[sorted[i]] = i;
	}
	ll cnt = 0;
	rep(i,0,N) {
		if (i % 2 == 0 && map[ais[i]] % 2 == 1) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
