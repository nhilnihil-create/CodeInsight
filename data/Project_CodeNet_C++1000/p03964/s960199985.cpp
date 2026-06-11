#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	long a = 1;
	long b = 1;

	for (int i = 0; i < N; i++) {
		int T, A;
		cin >> T >> A;

		long int k = max((a + T - 1) / T, (b + A - 1) / A);
		a = T * k;
		b = A * k;

	}

	cout << a + b << endl;

	return 0;
}