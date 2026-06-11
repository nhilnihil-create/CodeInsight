#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	// map<int, int> mp;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			int p = m * i  + n * j - 2 * i * j;
			// cout << p << endl;
			if (k == p) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	// if (mp[k]) cout << "Yes" << endl;
	// else cout << "No" << endl;
	cout << "No" << endl;
}

int main() {
	solve();
	return 0;
}