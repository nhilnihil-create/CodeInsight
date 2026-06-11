#include <bits/stdc++.h>
#define SZ(v) ((int)((v).size()))
using namespace std;
using ll = long long;

template<typename T>
vector<T> compress(vector<T> vec) {
	vector<pair<T, int>> util(SZ(vec));
	for (int i = 0; i < SZ(vec); ++i) {
		util[i] = {vec[i], i};
	}
	sort(util.begin(), util.end());
	vector<int> res = vec;
	int pos = 0;
	for (int i = 0; i < SZ(vec); ++i) {
		if (i > 0 && util[i].first > util[i-1].first) ++pos;
		res[util[i].second] = pos;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a = compress(a);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i%2 != a[i]%2) ++cnt;
	}
	cout << cnt/2 << "\n";
}
