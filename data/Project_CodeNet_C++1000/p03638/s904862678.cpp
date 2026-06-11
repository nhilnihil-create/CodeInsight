#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w, n; cin >> h >> w >> n;
	vector<int> color;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (a--) {
			color.push_back(i + 1);
		}
	}
	vector<vector<int>> c(h, vector<int>(w));
	int index = 0;
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; j++) {
				c[i][j] = color[index];
				index++;
			}
		}
		else {
			for (int j = w - 1; j >= 0; j--) {
				c[i][j] = color[index];
				index++;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << c[i][j];
			if (j != w - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}