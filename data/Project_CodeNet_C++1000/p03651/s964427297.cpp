#include <bits/stdc++.h>
using namespace std;

int my_gcd(int A, int B) {
	while (A > 0 && B > 0) {
		if (A > B) {
			A = A % B;
		} else {
			B = B % A;
		}
	}
	// A or B =0
	return A + B;
}

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N, K;
	scanf("%d %d", &N, &K);

	int A;
	scanf("%d", &A);

	int a_max = A;
	int a_gcd = A;

	for (int i = 1; i < N; i++) {
		scanf("%d", &A);
		a_gcd = my_gcd(A, a_gcd);
		a_max = max(a_max, A);
	}
	// cout << "a_gcd=" << a_gcd << "\na_max=" << a_max << "\n";
	if (a_max == K || a_max > K && K % a_gcd == 0) {
		cout << "POSSIBLE";
	} else {
		cout << "IMPOSSIBLE";
	}

	return 0;
}