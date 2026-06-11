#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define mp make_pair
#define pb push_back
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
	ll N, W;
	cin >> N >> W;
	ll w0, v0;
	cin >> w0 >> v0;

	vector<vector<ll>> v(4);
	v[0].pb(v0);

	for (int i = 1; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		v[a-w0].pb(b);
	}

	for (int i = 0; i < 4; i++) sort(RALL(v[i]));

	vector<vector<ll>> sum(4);
	for (int i = 0; i < 4; i++) {
		sum[i].pb(0);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			sum[i].pb(sum[i][j] + v[i][j]);
		}
	}

	ll ans = 0;
	for (int i = 0; i <= (int)v[0].size(); i++) {
		for (int j = 0; j <= (int)v[1].size(); j++) {
			for (int k = 0; k <= (int)v[2].size(); k++) {
				for (int l = 0; l <= (int)v[3].size(); l++) {
					ll tmp_w = w0*i + (w0+1)*j + (w0+2)*k + (w0+3)*l;
					if (tmp_w <= W) ans = max(ans, sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l]);
				}
			}
		}
	}

	cout << ans << endl;
    return 0;
}
