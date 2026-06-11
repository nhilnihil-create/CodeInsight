#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N, M;
	scanf("%d %d", &N, &M);

	vector<bool> e(N, true);
	int A, B;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		e[A - 1] = !e[A - 1];
		e[B - 1] = !e[B - 1];
	}
	for (int i = 0; i < N; i++) {
		if (!e[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}