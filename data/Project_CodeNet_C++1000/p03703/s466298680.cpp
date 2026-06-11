#include "bits/stdc++.h"
using namespace std;

static long long N, K, ANS = 0, B[200010] = {}, BIT[200010] = {};
vector<long long> V;

void Add(int X, long long Y) {
	for (int i = X; i <= N + 1; i += i & -i) BIT[i] += Y;
}

long long Sum(int X) {
	long long Ret = 0;
	for (int i = X; i > 0; i -= i & -i) Ret += BIT[i];
	return Ret;
}

int main() {
	cin >> N >> K;
	V.push_back(0);
	for (int i = 0; i < N; i++) {
		long long A;
		cin >> A;
		A -= K;
		B[i + 1] = B[i] + A;
		V.push_back(B[i + 1]);
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 0; i <= N; i++) {
		int X = lower_bound(V.begin(), V.end(), B[i]) - V.begin() + 1;
		ANS += Sum(X);
		Add(X, 1);
	}
	cout << ANS;
}