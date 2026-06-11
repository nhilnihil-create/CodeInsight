#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int md = 1e9 + 7;
const int inv2 = 5e8 + 4;

int n, m;
string s;
int f[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	m = s.size();

	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = (f[i-1][0] + f[i-1][1]) % md; 
		for (int j = 1; j <= n; ++j) {
			f[i][j] = (f[i-1][j+1] + f[i-1][j-1] * 2LL % md) % md;
		}
	}

	int inv = 1;
	for (int i = 1; i <= m; ++i) inv = 1LL * inv * inv2 % md;
	cout << 1LL * f[n][m] * inv % md << endl;
}