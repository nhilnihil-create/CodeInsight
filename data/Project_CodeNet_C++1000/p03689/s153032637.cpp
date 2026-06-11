#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 505;

i64 mx[N][N];

int main() {
#ifdef HOME
	freopen("agc16c.in", "r", stdin);
	freopen("agc16c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	i64 huge;
	int n, m, h, w;

	cin >> n >> m >> h >> w;
	if (n % h == 0 && m % w == 0)
		cout << "No\n";
	else {
		cout << "Yes\n";

		huge = i64(5e8) - i64(5e8) % (h * w - 1);
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mx[i][j] = ((i - 1) % h == 0 && (j - 1) % w == 0) ? huge : -(huge / (h * w - 1) + 1);

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cout << mx[i][j] << " \n"[j == m]; }

	return 0; }
