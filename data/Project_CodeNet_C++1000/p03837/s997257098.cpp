// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100, M = 1000, INF = 0x3f3f3f3f;

int ii[M], jj[M], ww[M], dd[N][N];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			dd[i][j] = INF;
		dd[i][i] = 0;
	}
	for (int h = 0; h < m; h++) {
		int i, j, w; cin >> i >> j >> w, i--, j--;
		ii[h] = i, jj[h] = j, ww[h] = w;
		dd[i][j] = dd[j][i] = w;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dd[i][j] = min(dd[i][j], dd[i][k] + dd[k][j]);
	int ans = 0;
	for (int h = 0; h < m; h++)
		if (ww[h] > dd[ii[h]][jj[h]])
			ans++;
	cout << ans << '\n';
	return 0;
}
