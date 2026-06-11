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
	int n, m;
	cin >> n >> m;
	vector<string> v(n), u(m);
	rep(i,n) cin >> v[i];
	rep(i,m) cin >> u[i];
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			bool b = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (v[i + k][j + l] == u[k][l]) continue;
					b = false;
				}
			}
			if (b) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
}

int main() {
	solve();
	return 0;
}