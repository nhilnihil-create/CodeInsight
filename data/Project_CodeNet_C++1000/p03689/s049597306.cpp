#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9-1, MAXN = 505;

int n, m, a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	if (n%a == 0 && m%b == 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		static int s[MAXN][MAXN];
		if (n%a != 0) {
			for (int i = 1; i <= n; i += a)
				for (int j = 1; j <= m; j++)
					s[i][j] = INF;
			for (int i = a; i <= n; i += a)
				for (int j = 1; j <= m; j++)
					s[i][j] = -INF-1;
		} else {
			for (int i = 1; i <= m; i += b)
				for (int j = 1; j <= n; j++)
					s[j][i] = INF;
			for (int i = b; i <= m; i += b)
				for (int j = 1; j <= n; j++)
					s[j][i] = -INF-1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << s[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
