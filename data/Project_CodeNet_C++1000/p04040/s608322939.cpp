#include <bits/stdc++.h>

#define ft first
#define sd second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int D = 1000 * 1000 * 1000 + 7, MAXN = 2 * 100 * 1000 + 123;


void multi(int& x, int y) { x = (ll)x * y % D; }
int inv(int x) {
	int res = 1;
	for (int i = D - 2; i; i >>= 1, x = (ll)x * x % D)
		if (i & 1)
			res = (ll)res * x % D;
	return res;
}

int r, c, a, b, ans, jav, fact[MAXN];


int main() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = (ll)fact[i - 1] * i % D;
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r - a; i++) {
		jav = fact[b + i - 1];
		multi(jav, inv(fact[b - 1]));
		multi(jav, inv(fact[i]));
		multi(jav, fact[r - i + c - b - 2]);
		multi(jav, inv(fact[r - i - 1]));
		multi(jav, inv(fact[c - b - 1]));
		ans += jav;
		ans %= D;
	}
	cout << ans;
	return 0;
}