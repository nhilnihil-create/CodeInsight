#include <bits/stdc++.h>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for (T& x : v) { is >> x; }
	return is;
}

int dfs(int cur, vector<vector<int>>& g) {
	vector<int> a;
	for (auto to : g[cur]) { a.emplace_back(dfs(to, g)); }
	if(a.empty()) return 1;
	sort(all(a), greater<int>());

	int res = 0;
	rep(i, a.size()) { res = max(res, a[i] + i); }

	//show(cur)
	//show(res + 1)
	//cout << a << endl;
	return res + 1;
}

signed main() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	rep(i, n - 1) {
		int a;
		cin >> a;
		a--;
		g[a].emplace_back(i+1);
	}

	cout << dfs(0, g) - 1 << endl;
}
