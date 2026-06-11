#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, pair<int, int>>PP;
typedef long long ll;
ll inf = 1e9;

int main() {
	vector<int>cnt(4, 0);
	vector<ll>v[4];
	int n, W;
	cin >> n >> W;
	ll w0,v0;
	cin >> w0 >> v0;
	v[0].push_back(v0);
	cnt[0]++;
	for (int i = 1; i < n; i++) {
		ll w,V;
		cin >> w>>V;
		cnt[w - w0]++;
		v[w - w0].push_back(V);
	}
	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(),greater<ll>());
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
		v[i].insert(v[i].begin(), 0);
	}
	ll ans = 0;
	for (int i = 0; i <= cnt[0]; i++) {
		for (int j = 0; j <= cnt[1]; j++) {
			for (int k = 0; k <= cnt[2]; k++) {
				for (int l = 0; l <= cnt[3]; l++) {
					if (w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l <= W) {
						ans = max(ans, v[0][i] + v[1][j] + v[2][k] + v[3][l]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}