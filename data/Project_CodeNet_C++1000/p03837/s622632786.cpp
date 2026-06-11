#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000], b[1000], c[1000], d[100][100], ans = 0;

int main() {
	cin >> n >> m;
	fill(d[0], d[n], 1e5);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		d[a[i]][b[i]] = c[i];
		d[b[i]][a[i]] = c[i];
	}
	for (int i = 0; i < n; i++)
		d[i][i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

	for (int i = 0; i < m; i++)
		if (d[a[i]][b[i]] != c[i])
			ans++;
	cout << ans << endl;

}
