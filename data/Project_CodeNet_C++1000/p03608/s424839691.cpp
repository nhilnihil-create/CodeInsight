#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, R, A, B, C, ans = INT_MAX;
	cin >> N >> M >> R;
	vector<int> r(R);
	for (int& i : r) cin >> i;
	sort(r.begin(), r.end());
	vector<vector<int>> a(N, vector<int>(N, INT_MAX));
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		a[A - 1][B - 1] = C;
		a[B - 1][A - 1] = C;
	}
	for (int i = 0; i < N; i++) a[i][i] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[j][i] == INT_MAX) continue;
			for (int k = 0; k < N; k++) {
				if (a[i][k] == INT_MAX) continue;
				a[j][k] = min(a[i][k] + a[j][i], a[j][k]);
			}
		}
	}
	do {
		int b = 0;
		for (int i = 1; i < R; i++) b += a[r[i - 1] - 1][r[i] - 1];
		ans = min(b, ans);
	} while (next_permutation(r.begin(), r.end()));
	cout << ans;
}