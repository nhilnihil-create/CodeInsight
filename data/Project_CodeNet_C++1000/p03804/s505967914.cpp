#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int main() {
	int N, M;
	string A[MAX], B[MAX];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	string ans = "No";
	for (int x = 0; x <= N - M; x++) {
		for (int y = 0; y <= N - M; y++) {
			bool flg = true;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					if (A[x + i][y + j] != B[i][j]) {
						flg = false;
					}
				}
			}
			if (flg) {
				ans = "Yes";
			}
		}
	}
	cout << ans << endl;
	return 0;
}
