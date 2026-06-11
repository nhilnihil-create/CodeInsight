#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0

int n, m;
map <int, int> G;

int32_t main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		G[a - 1]++;
		G[b - 1]++;
	}
	for(int i = 0; i < n; ++i) {
		cout << G[i] << '\n';
	}
	time;
}