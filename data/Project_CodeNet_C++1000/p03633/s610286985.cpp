#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int64_t gcd(int64_t a, int64_t b) {
	if (!b) return a;
	else return gcd(b, a % b);
}

int64_t lcm(int64_t a, int64_t b) {
	int64_t g = gcd(a, b);
	return a / g * b;
}

int main() {
	int N;
	cin >> N;

	int64_t ans = 1;
	int64_t n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		ans = lcm(ans, n);
	}

	cout << ans << endl;
}