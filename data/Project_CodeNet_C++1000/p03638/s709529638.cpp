#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n);
	vector<vector<int>> grid(h, vector<int>(w));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[k] == 0) k++;
			grid[i][j] = k+1;
			a[k]--;
		}
		if (i % 2 == 1) {
			reverse(grid[i].begin(), grid[i].end());
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << grid[i][j];
			if (j < w-1) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}