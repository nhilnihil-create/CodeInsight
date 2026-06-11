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

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for (auto &t : a) {
		cin >> t;
	}
	vector<int> seen = a;
	sort(seen.begin(), seen.end());
	seen.resize(unique(seen.begin(), seen.end()) - seen.begin());
	reverse(seen.begin(), seen.end());
	seen.push_back(0);
	map<int, int> moc;
	map<int, int> occ;
	for (int i = 0; i < n; i++) {
		if (!moc.count(a[i])) moc[a[i]] = i;
		occ[a[i]]++;
	}
	int cm = n;
	int cnt = 0;
	for (int i = 0; i + 1 < (int)seen.size(); i++) {
		cm = min(cm, moc[seen[i]]);
		cnt += occ[seen[i]];
		ans[cm] += (seen[i] - seen[i + 1]) * cnt;
	} 
	for (auto t : ans) {
		cout << t << ' ';
	}
	cout << '\n';
}
