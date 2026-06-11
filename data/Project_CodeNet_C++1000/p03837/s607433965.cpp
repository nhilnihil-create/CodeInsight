/**
*    author:  boutarou
*    created: 11.06.2020 22:58:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define fcout cout << fixed << setprecision(15)
using lint = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int INF = 1e8;
const double PI = 3.1415926535897932;

int n, m;
int a[1005], b[1005], c[1005];
int dist[105][105];

int ans = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	
	rep(i, n) {
		rep(j, n) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	rep(i, m) {
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	rep(i, m) {
		if (dist[a[i]][b[i]] != c[i]) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}