#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	for (int i = 0; i <= N; i++) for (int j = 0; j <= M; j++) if (i * M + j * N - i * j * 2 == K) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}

