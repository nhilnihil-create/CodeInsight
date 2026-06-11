#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>T(N);
	vector<long long>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i] >> A[i];
	}
	long long x = 1;
	long long y = 1;
	for (int i = 0; i < N; ++i) {
		long long xsub = (x + T[i] - 1) / T[i];
		long long ysub = (y + A[i] - 1) / A[i];
		x = max(xsub, ysub)*T[i];
		y = max(xsub, ysub)*A[i];
	}
	cout << (long long)(x + y) << endl;
	return 0;
}
