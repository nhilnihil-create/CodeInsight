#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t N, M;
	cin >> N >> M;

	int64_t ans = -1;
	if (2 * N == M) {
		ans = N;
	}
	else if (2 * N > M) {
		ans = M / 2;
	}
	else {
		int64_t m = M - 2 * N;
		ans = N + m / 4;
	}

	cout << ans << endl;
}