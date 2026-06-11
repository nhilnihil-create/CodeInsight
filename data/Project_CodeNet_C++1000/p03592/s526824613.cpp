#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M, K; cin >> N >> M >> K;
	if (K % M == 0 || K % N == 0) cout << "Yes" << endl;
	else {
		for (int i = 0; i <= N; i++) {
			if (N - 2 * i != 0) {
				if ((K - (i * M)) % (N - (2 * i)) == 0) {
					if ((K - (i * M)) / (N - (2 * i)) < M && (K - (i * M)) / (N - (2 * i)) >= 0) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
		cout << "No" << endl;
	}
}