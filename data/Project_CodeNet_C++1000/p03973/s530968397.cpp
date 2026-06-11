#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[100000], Cur = 2, ANS = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ANS = A[0] - 1;
	for (int i = 1; i < N; i++) {
		if (Cur == A[i]) Cur++;
		else {
			ANS += (A[i] - 1) / Cur;
		}
	}
	cout << ANS << endl;
}