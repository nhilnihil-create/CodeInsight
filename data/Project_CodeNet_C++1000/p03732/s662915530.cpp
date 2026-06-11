#include <bits/stdc++.h>

using namespace std;

#define intt long long 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;

int n, W;

struct Item {
	int w;
	int v;
};

Item a[N];

intt pref[N][4];

int main() {

	FAST;

	cin >> n >> W;
	cin >> a[0].w >> a[0].v;
	int w = a[0].w;
	vector <int> v[4];
	v[0].push_back(a[0].v);
	for (int i = 1; i < n; i ++) {
		cin >> a[i].w >> a[i].v;
		v[a[i].w - w].push_back(a[i].v);
	}
	for (int i = 0; i < 4; i ++) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < v[i].size(); j ++) {
			pref[j + 1][i] = pref[j][i] + v[i][j];
		}
	}
	intt ans = 0;
	for (int i = 0; i <= min(int(v[0].size()), max(0, n)); i ++) {
		for (int j = 0; j <= min(int(v[1].size()), max(0, n - i)); j ++) {
			for (int k = 0; k <= min(int(v[2].size()), max(0, n - i - j)); k ++) {
				for (int c = 0; c <= min(int(v[3].size()), max(0, n - i - j - k)); c ++) {
					intt tw = 1LL * i * w + 1LL * j * (w + 1) + 1LL * k * (w + 2) + 1LL * c * (w + 3);
					if (tw <= 1LL * W) {
						ans = max(ans, pref[i][0] + pref[j][1] + pref[k][2] + pref[c][3]);
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}