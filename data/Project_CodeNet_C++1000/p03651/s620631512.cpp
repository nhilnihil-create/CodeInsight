#include "bits/stdc++.h"
using namespace std;
int GCD(int A, int B) {
	if (B == 0) return A;
	else return GCD(B, A % B);
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int>A(N);
	int MAX = 0;
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		if (MAX < A.at(i)) MAX = A.at(i);
	}
	int gcd = A.at(0);
	for (int i = 0; i < N; i++) {
		gcd = GCD(gcd, A.at(i));
	}
	if (K % gcd == 0 && K <= MAX) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}
