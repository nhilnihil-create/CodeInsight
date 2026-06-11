// arc067_a.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A(1005);
	for (int i = 2; i <= n; i++) {
		int a = i;
		for (int j = 2; a > 1; j++) {
			while (a % j == 0) {
				A[j]++;
				a /= j;
			}
		}
	}

	long long sum = 1;
	const long long mod7 = 1e9 + 7;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0) continue;
		sum = (sum * (A[i] + 1)) % mod7;
	}
	cout << sum;
}