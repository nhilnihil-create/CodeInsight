#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL A[300][300];
bool use[300][300];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	memset(use, -1, sizeof(use));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				if (A[i][j] > A[i][k] + A[k][j]) {
					cout << -1 << endl;
					return 0;
				}
				if (A[i][j] == A[i][k] + A[k][j]) use[i][j] = 0;
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (use[i][j]) ans += A[i][j];
		}
	}
	cout << ans << endl;
}