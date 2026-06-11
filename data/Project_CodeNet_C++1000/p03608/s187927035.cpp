#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> r(R);
	for (int i = 0; i < R; i++) {
		cin >> r[i];
		r[i]--;
	}
	sort(r.begin(), r.end());
	vector<vector<int>> D(N, vector<int>(N, 1<<29));
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		D[A - 1][B - 1] = C;
		D[B - 1][A - 1] = C;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int MIN = 1 << 29;
	do {
		int sum = 0;
		for (int i = 0; i < R - 1; i++) sum += D[r[i]][r[i + 1]];
		MIN = min(MIN, sum);
	} while (next_permutation(r.begin(), r.end()));
	cout << MIN << endl;
}