#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> c(h + 2, vector<char>(w + 2));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << c[i][j];
		}
		cout << endl;
		for (int j = 1; j <= w; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}