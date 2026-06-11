#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, X[100000], Cur = 0, ANS = 1, MOD = 1000000007;
	vector<long long> V;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	for (int i = 0; i < N; i++) {
		if (Cur >= X[i]) {
			V.push_back(i + 1);
		}
		else {
			Cur += 2;
		}
	}
	for (int i = 0; i < V.size(); i++) {
		ANS *= (V[i] - i);
		ANS %= MOD;
	}
	for (int i = V.size(); i < N; i++) {
		ANS *= (N - i);
		ANS %= MOD;
	}
	cout << ANS << endl;
}