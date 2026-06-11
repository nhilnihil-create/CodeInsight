#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define myfill(a, val, type) fill((type *)a, (type *)a+sizeof(a)/sizeof(type), val)
const int INF = 1001001001;

int main() {
	int n, m, R;
	cin >> n >> m >> R;
	vector<int> r(R);
	for (int i = 0; i < R; i++) {
		cin >> r[i];
		r[i]--;
	}
	int d[200][200]; myfill(d, INF, int);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = d[b][a] = c;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = INF;
	sort(r.begin(), r.end());
	do {
		int now = 0;
		for (int i = 0; i < r.size()-1; i++) {
			now += d[r[i]][r[i+1]];
		}
		ans = min(ans, now);
	} while (next_permutation(r.begin(), r.end()));
	cout << ans << endl;
	return 0;
}