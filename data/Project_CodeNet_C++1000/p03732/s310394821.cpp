#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, W, w[100], V, v[4][110] = {}, C[4] = {}, MAX = 0;
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> V;
		v[w[i] - w[0]][C[w[i] - w[0]] + 1] = V;
		C[w[i] - w[0]]++;
	}
	for (int i = 0; i < 4; i++) {
		sort(v[i] + 1, v[i] + C[i] + 1, greater<long long>());
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= C[i]; j++) {
			v[i][j] += v[i][j - 1];
		}
	}
	long long w0 = w[0], w1 = w[0] + 1, w2 = w[0] + 2, w3 = w[0] + 3;
	for (int i = 0; i <= min(W / w3, C[3]); i++) {
		long long W1 = W - w3 * i;
		for (int j = 0; j <= min(W1 / w2, C[2]); j++) {
			long long W2 = W1 - w2 * j;
			for (int k = 0; k <= min(W2 / w1, C[1]); k++) {
				long long W3 = W2 - w1 * k;
				int l = min(W3 / w0, C[0]);
				MAX = max(MAX, v[3][i] + v[2][j] + v[1][k] + v[0][l]);
			}
		}
	}
	cout << MAX;
}