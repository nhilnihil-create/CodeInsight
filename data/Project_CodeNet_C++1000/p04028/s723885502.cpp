#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1e9 + 7;

int n, m;
string s;
int f[N][N];

void add(int &x,int y) { x = x + y < MOD ? x + y : x + y - MOD; }
int mult(int x,int y) { return 1LL * x * y % MOD; }

int fpow(int x,int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = mult(ret, x);
		x = mult(x, x);
		y >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	f[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i][0] = f[i - 1][0]; add(f[i][0], f[i - 1][1]);
		for (int j = 1; j <= i; ++j) {
			f[i][j] = mult(2, f[i - 1][j - 1]);
			add(f[i][j], f[i - 1][j + 1]);
		}
	}
	cin >> n >> s; m = s.size();
	cout << mult(f[n][m], fpow(2, MOD - 1 - m));
}