#include <bits/stdc++.h>
using namespace std;

using lli = long long;
using pii = pair<int, int>;
using pll = pair<lli, lli>;
using Double = long double;
template<typename T>
using Vector = vector<vector<T>>;
template<typename T>
using Prior = priority_queue<T>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;

#define IOS() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define Push push_back
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()

void solve() {
	lli n, L, sum = 0;
	cin >> n >> L;

	vector<lli> v(n);
	for (auto &x : v) cin >> x, sum += x;

	int tok = -1;
	for (int i = 1; i < n; ++i) {
		if (v[i] + v[i - 1] >= L) {
			tok = i;
			break;
		}
	}

	if (tok == -1) {
		cout << "Impossible\n";
		return;
	}

	cout << "Possible\n";
	for (int i = 1; i < tok; ++i) cout << i << "\n";
	for (int i = n-1; i >= tok; --i) cout << i << "\n";
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}