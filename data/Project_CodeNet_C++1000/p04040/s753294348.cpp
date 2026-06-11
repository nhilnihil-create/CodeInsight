#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 10, MOD = 1e9 + 7;
int n, m, A, B, ans;
int F[MAX_N];
int Fdiv[MAX_N];

int _sum (int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;

	return c;
}

int _mul (int a, int b) {
	int c = 1LL * a * b % MOD;
	return c;
}

int _pow (int a, int b) {
	if (!b)
		return 1;

	int res = _pow(a, b >> 1);
	res = _mul(res, res);

	if (b & 1)
		res = _mul(res, a);

	return res;
}

int _choose (int a, int b) {
	if (min(a, b) < 0 || b < a)
		return 0;

	return _mul(F[b], _mul(Fdiv[a], Fdiv[b - a]));
}

void pre_process() {
	F[0] = Fdiv[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		F[i] = _mul(F[i - 1], i);
		Fdiv[i] = _pow(F[i], MOD - 2);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pre_process();
	cin >> n >> m >> A >> B;
	A = n - A;
	B = m - B;
	int x = A, y = m - B + 1;
	while (x && y <= m) {
		ans = _sum(ans, _mul(_choose(x - 1, x + y - 2), _choose(n - x, n - x + m - y)));
		x--;
		y++;
	}

	cout << ans << "\n";
	return 0;
}