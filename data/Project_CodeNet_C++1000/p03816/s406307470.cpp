#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, cnt = 0, x; cin >> n;
	unordered_map<int,int> f;
	for (int i = 0; i < n; i++) {
		cin >> x;
		f[x]++;
	}
	for (auto fi : f) {
		cnt += (fi.second - 1);
	}
	cnt = ((cnt + 1) / 2) * 2;
	cout << n - cnt << "\n";
	return 0;
}