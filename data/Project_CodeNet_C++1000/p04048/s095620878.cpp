#include "bits/stdc++.h"
using namespace std;

long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	long long N, X;
	cin >> N >> X;
	long long G = GCD(N, X);
	N /= G, N--;
	cout << N * G * 3 << endl;
}