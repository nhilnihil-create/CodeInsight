#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1010101010

using namespace std;

int main()
{
	int n, m, o;
	cin >> n >> m >> o;
	vector<int> r(o);
	for (int i = 0; i < o; i++) {
		cin >> r[i];
		r[i]--;
	}
	sort(r.begin(), r.end());

	vector<vector<int>> a(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		s--;
		t--;
		a[s][t] = u;
		a[t][s] = u;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	int mn = INF;
	do {
		int tmp = 0;
		for (int i = 0; i < o - 1; i++) {
			tmp += a[r[i]][r[i + 1]];
		}
		mn = min(mn, tmp);
	} while (next_permutation(r.begin(), r.end()));
	cout << mn << endl;

	return 0;
}