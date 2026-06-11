#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<bool>A(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			if (A[y]) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
			else {
				A[y] = true;
			}
		}
		if (y == N) {
			if (A[x]) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
			else {
				A[x] = true;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}