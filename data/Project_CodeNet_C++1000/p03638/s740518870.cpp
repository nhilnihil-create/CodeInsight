#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int h, w, n;
	cin >> h >> w >> n;

	vector<int> a(n);
	vector<vector<int>> ar(h, vector<int>(w, 0));
	rep (i, 0, n)
		cin >> a[i];

	int i = 0, j = 0, k = 0;
	int count = 0;
	while (i < h) {
		ar[i][j] = k + 1;
		if (++count == a[k]) {
			k++;
			count = 0;
		}

		if (i & 1) {
			i += (j > 0) ? 0 : 1;
			j += (j > 0) ? -1 : 0;
		} else {
			i += (j < w - 1) ? 0 : 1;
			j += (j < w - 1) ? 1 : 0;
		}
	}

	rep (i, 0, h) {
		rep (j, 0, w) {
			cout << ar[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}
