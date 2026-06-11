#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

bool solve() {
	int n; cin >> n;
	multiset<int> s;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		s.insert(x);
	}
	int diam = *s.rbegin();
	int lowestAnchor = diam;
	for (int i = 0; i <= diam; ++i) {
		int dist = max(i, diam-i);
		chmin(lowestAnchor, dist);
		auto it = s.find(dist);
		if (it == s.end()) return false;
		s.erase(it);
	}
	if (!s.empty() && *s.begin() <= lowestAnchor) {
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (solve()) {
		cout << "Possible\n";
	} else {
		cout << "Impossible\n";
	}
}
