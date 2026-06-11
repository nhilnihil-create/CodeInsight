#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N;
	cin >> N;

	int64_t T = 1, A = 1;
	for (int i = 0; i < N; i++) {
		int64_t t, a;
		cin >> t >> a;

		int64_t n, x, y;
		x = T / t;
		y = A / a;
		if (T % t) x++;
		if (A % a) y++;
		n = max(x, y);
		T = t * n;
		A = a * n;
	}

	cout << T + A << endl;
}
