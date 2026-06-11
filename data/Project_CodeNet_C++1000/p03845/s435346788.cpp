#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;

int n, t[110], m;
P drink[110]; 
int main() {
	cin >> n;
	int all = 0;
	rep(i, n) {
		cin >> t[i];
		all += t[i];
	}
	cin >> m;
	rep(i, m) {
		int p, x; cin >> p >> x;
		drink[i] = make_pair(p-1,x);
	}
	rep(i, m) {
		auto p = drink[i].first, x = drink[i].second;
		cout << all - t[p] + x << endl;
	}
	return 0;
}