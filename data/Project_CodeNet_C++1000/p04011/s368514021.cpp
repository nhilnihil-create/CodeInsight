#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;

	int base, extra;
	if (N <= K) {
		base = X * N;
		extra = 0;
	}
	else {
		base = X * K;
		extra = Y * (N - K);
	}

	cout << base + extra << endl;
}