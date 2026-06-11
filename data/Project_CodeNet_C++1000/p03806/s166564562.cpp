#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ull<<(n))

map<pair<int, int>,int> mks(vector<pair<pair<int, int>, int>> abc) {
	int n = abc.size();
	map<pair<int, int>, int> r;
	r[make_pair(0,0)] = 0;
	for (unsigned i = 0; i < (1u << n); i++) {
		int sa = 0, sb = 0, sc = 0;
		for (unsigned j = 0; j < n; j++) {
			if (i & (1u << j)) {
				sa += abc[j].first.first;
				sb += abc[j].first.second;
				sc += abc[j].second;
			}
		}
		if (r.find(make_pair(sa, sb)) == r.end()) r[make_pair(sa, sb)] = sc;
		else [](int a, int& b) {b = min(a, b); }(sc, r[make_pair(sa, sb)]);
	}
	return r;
}

int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<pair<pair<int, int>, int>> abc[2];
	abc[0].resize(n/2);
	abc[1].resize(n - (n / 2));
	for (auto& f : abc)	for (auto& e : f) cin >> e.first.first >> e.first.second >> e.second;
	auto s1 = mks(abc[0]), s2 = mks(abc[1]);
	int r = 1000000;
	for (auto& e : s1) {
		for (int i = 1; i <= 400; i++) {
			auto v = s2.find(make_pair(ma * i - e.first.first, mb * i - e.first.second));
			if (v != s2.end()) {
				r = min(r, e.second + v->second);
			}
		}
	}
	cout << (r == 1000000 ? -1 : r) << endl;
}
