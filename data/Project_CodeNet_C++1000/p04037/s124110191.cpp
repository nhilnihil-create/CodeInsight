#include "bits/stdc++.h"
using namespace std;

int main() {
	static long long N, A[100000];
	static bool X[100000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	X[0] = true;
	for (int i = 1; i < N; i++) {
		if (A[i] != A[i - 1]) X[i] = true;
		else X[i] = !X[i - 1];
	}
	reverse(A, A + N), reverse(X, X + N);
	for (int i = N - 1; i >= 0; i--) {
		if (i - A[i] == 0 && X[i]) {
			cout << "First" << endl;
			return 0;
		}
		if (i - A[i] + 1 <= 0) {
			cout << (X[i] == (A[i] - i + 1) % 2 ? "First" : "Second") << endl;
			return 0;
		}
	}
}