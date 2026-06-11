#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, X[30], ANS = 0;
	static long long A[100000], B[100000];
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	long long P = (1 << 30) - 1 - K;
	for (int i = 0; i < 30; i++) X[i] = K % 2, K /= 2;
	for (int i = 0; i < N; i++) {
		if ((A[i] & P) == 0) ANS += B[i];
	}
	for (int i = 29; i >= 0; i--) {
		if (X[i] == 0) continue;
		long long Y[30] = {}, Z = 0, COUNT = 0;
		for (int j = 29; j > i; j--) Y[j] = 1 - X[j];
		Y[i] = 1;
		for (int j = 29; j >= 0; j--) Z *= 2, Z += Y[j];
		for (int j = 0; j < N; j++) {
			if ((A[j] & Z) == 0) COUNT += B[j];
		}
		ANS = max(ANS, COUNT);
	}
	cout << ANS << endl;
}