#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> E;
const LL MOD = 1000000007LL;
LL A[300][300];
bool use[300][300];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	memset(use, -1, sizeof(use));
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][k] + A[k][j] < A[i][j]) {
					cout << -1 << endl;
					return 0;
				}
				else if (k != i && k != j && A[i][k] + A[k][j] == A[i][j]) {
					use[i][j] = 0;
				}
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