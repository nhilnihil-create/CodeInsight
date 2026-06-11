#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	char v[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		int t = 2;
		while (t--) {
			for (int j = 0; j < m; ++j) {
				cout << v[i][j];
			}
			cout << endl;
		}
	}
}

















