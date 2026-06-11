#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 102;

vector<int> ind[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	for (int i = 0; i < n; i++) {
		ind[a[i]].push_back(a[i]);
	}
	int mx = *max_element(a.begin(), a.end());
	vector<int> d(mx + 1);
	vector<int> to(mx + 1);
	for (int i = 0; i <= mx; i++) {
		d[i] = max(i, mx - i);
	}
	for (int i = 0; i <= mx; i++) {
		if (ind[d[i]].empty()) {
			cout << "Impossible\n";
			return 0;
		}
		to[i] = ind[d[i]].back();
		ind[d[i]].pop_back();
	}
	for (int i = 0; i <= mx; i++) {
		d[i]++;
	} 
	for (int i = 0; i <= mx; i++) {
		ind[d[i]].clear();
	}
	for (int i = 0; i < N; i++) {
		if (!ind[i].empty()) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
}