//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int ll

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 500 + 20;
int n, m, x, y;
int a[N][N];
ll sum;

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> x >> y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i % x == x - 1 && j % y == y - 1)
				a[i][j] = -(x * y - 1) * 501 - 1;
			else 
				a[i][j] = 501;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += a[i][j];

	if (sum <= 0) return cout << "No\n", 0;

	cout << "Yes\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}
