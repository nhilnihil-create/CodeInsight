#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N, A[MAX], ans = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int maxa, mina;
	maxa = INT_MIN;
	mina = INT_MAX;
	for (int i = 0; i < N - 1; i++) {
		maxa = max(maxa, A[i]);
		mina = min(mina, A[i]);
		if (maxa == mina)
			continue;
		if (A[i] == maxa && A[i] > A[i + 1]) {
			ans++;
			maxa = INT_MIN;
			mina = INT_MAX;
		} else if (A[i] == mina && A[i] < A[i+1]) {
			ans++;
			maxa = INT_MIN;
			mina = INT_MAX;
		}
	}
	cout << ans << endl;
	return 0;
}
