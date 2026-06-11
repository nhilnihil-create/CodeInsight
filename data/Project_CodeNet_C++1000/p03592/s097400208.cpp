#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	int N, M, K; cin >> N >> M >> K;
	bool flag = false;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (M * i + N * j - 2 * i * j == K) flag = true;
		}
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}