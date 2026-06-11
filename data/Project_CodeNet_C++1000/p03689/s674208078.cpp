#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e2 + 7;
 
long long t[N][N];
long long n, m, h, w;
 
int main() {
	cin >> n >> m >> h >> w;
	long long ps = n * m * 500;
	for (int i = h; i <= n; i += h) {
		for (int j = w; j <= m; j += w) {
			t[i][j] = -1 * (h * w - 1) * 500 - 1;
			ps += t[i][j] - 500;
		}
	}
	if (ps > 0) {
		cout << "Yes" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!t[i][j])
					t[i][j] = 500;
				cout << t[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << "No";
	return 0;
}
