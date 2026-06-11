#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, L, Q;
	cin >> N;
	vector<long long> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];
	cin >> L >> Q;
	long long K = log2(N);
	vector<vector<long long> > D(N, vector<long long>(K + 1));
	for (int i = 0; i < N; i++) {
		D[i][0] = upper_bound(X.begin(), X.end(), X[i] + L) - X.begin() - 1;
	}
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i < N; i++) {
			D[i][j] = D[D[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < Q; i++) {
		long long S, T;
		cin >> S >> T;
		S--, T--;
		if (S > T) swap(S, T);
		long long ANS = 0;
		for (int j = K; j >= 0; j--) {
			if (D[S][j] < T) {
				S = D[S][j];
				ANS += 1LL << j;
			}
		}
		cout << ANS + 1 << endl;
	}
}