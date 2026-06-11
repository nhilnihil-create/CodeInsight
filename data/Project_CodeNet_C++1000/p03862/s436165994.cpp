#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, X;
	cin >> N >> X;
	vector<long long>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	long long ans = 0;
	for (int i = 1; i < N; ++i) {
		if ((A[i-1]+A[i])>X) {
			long long num =  (A[i-1]+A[i]-X);
			ans += num;
			A[i] = max((long long)0,A[i]-num);
		}
	}
	cout << ans << endl;
	return 0;
}

