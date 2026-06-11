#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	int N, K;
	cin >> N >> K;
	int GCD, MAX;
	cin >> GCD;
	MAX = GCD;
	bool ans = true;
	for (int i = 1; i < N; i++) {
		int A;
		cin >> A;
		if (GCD > 1) GCD = gcd(A, GCD);
		MAX = max(MAX, A);
	}
	if (MAX < K) ans = false;
	if (ans && K % GCD != 0) ans = false;
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}