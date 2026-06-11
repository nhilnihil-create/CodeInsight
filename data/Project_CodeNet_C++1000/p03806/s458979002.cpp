//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
typedef long long ll;

using namespace std;

#define MAX 401

signed main() {
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<vector<int>> v(MAX, vector<int>(MAX, INF));
	v[0][0] = 0;
	rep(_, n) {
		int a, b, c; cin >> a >> b >> c;
		for (int i = MAX - 1; i >= 0; i--)
			for (int j = MAX - 1; j >= 0;j--) {
			if (v[i][j] != INF) {
				v[i + a][j + b] = min(v[i + a][j + b], v[i][j] + c);
			}
		}
	}
	int ans = INF;
	int k = 1;
	while (k * max(m1, m2) < 401) {
		ans = min(ans, v[k * m1][k * m2]);
		k++;
	}
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
}