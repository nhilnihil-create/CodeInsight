#include <bits/stdc++.h>
#define fi first
#define se second

typedef long long ll;
typedef std::pair < int, int > pr;
const int N = 305;

#define int ll
using std::cin;
using std::cout;

int n, dis[N][N], ans, P[N][N];
signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) cin >> dis[i][j];
	for (int k = 1; k <= n; ++k)
	    for (int i = 1; i <= n; ++i)
	        for (int j = 1; j <= n; ++j) {
	            if (i == j || j == k || i == k) continue;
	            if (dis[i][j] > dis[i][k] + dis[k][j]) return cout << -1 << '\n', 0;
	            if (dis[i][j] == dis[i][k] + dis[k][j]) P[i][j] = 1;
            }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) 
            if (! P[i][j]) ans += dis[i][j];
	cout << ans << '\n';
	return 0;
}

