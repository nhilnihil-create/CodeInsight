#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> a;

void input() {
	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
}

void solve() {
	input();
	// 木の直径を求める.
	int d = 0;
	for (auto ai : a)
		d = max(d, ai);
	// 各値がa中に何回出現するかを求める
	map<int, int> cnt;
	for (auto ai : a)
		++cnt[ai];
	// 直径中の頂点をremove
	for (int i = d; i >= (d + 1) / 2; --i) {
		if (d % 2 == 0 && i == d / 2)
			--cnt[i];
		else
			cnt[i] -= 2;
		if (cnt[i] < 0) {
			cout << "Impossible" << endl;
			return;
		}
	}
	for (auto& e : cnt) {
		if (e.second > 0 && e.first <= (d + 1) / 2) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;
	return;
}

int main() {
	solve();
}