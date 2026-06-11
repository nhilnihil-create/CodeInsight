#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A, B, C, D;
	bool check = false;
	cin >> N >> A >> B >> C >> D;
	for (int i = 0; i < N; i++) {
		long long X, Y;
		X = A + C * i - D * (N - i - 1);
		Y = A + D * i - C * (N - i - 1);
		if (X <= B && B <= Y) check = true;
	}
	if (check) cout << "YES";
	else cout << "NO";
}