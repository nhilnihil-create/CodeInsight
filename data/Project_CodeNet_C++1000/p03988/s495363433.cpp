#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[100], X[100] = {}, MIN, MAX;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i], X[A[i]]++;
	sort(A, A + N);
	MIN = A[0], MAX = A[N - 1];
	if (MIN * 2 - 1 == MAX) {
		if (X[MIN] != 2) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	else if (MIN * 2 == MAX) {
		if (X[MIN] != 1) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	else {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = MIN + 1; i <= MAX; i++) {
		if (X[i] < 2) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
}