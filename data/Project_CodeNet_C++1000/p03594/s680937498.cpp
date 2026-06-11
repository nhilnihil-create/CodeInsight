#include <bits/stdc++.h>
using namespace std;

const char s[] = {'R', 'Y', 'G', 'B'};

int n, m, d;
int a[505][505], b[505][505];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int sum = i + j;
			sum /= d;
			if (sum & 1) a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int dif = i - j;
			if (dif >= 0) dif /= d;
			else if (dif < 0) {
				if (dif % d == 0) dif /= d; else dif = dif / d - 1;
			}
			if (dif & 1) b[i][j] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cur = 2 * a[i][j] + b[i][j];
			cout << s[cur];
		}
		cout << endl;
	}
}