#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m, x, y;
int vis[N], a[N];

int main() {
	cin >> n >> m; vis[1] = 1;
	for(int i = 1;i <= n; ++i) a[i] = 1;
	for(int i = 1;i <= m; ++i) {
		cin >> x >> y;
		if(vis[x] == 1) vis[y] = 1;
		a[x]--; a[y]++;
		if(!a[x]) vis[x] = 0;
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
		if(vis[i] && a[i])
			ans++;
	cout << ans << endl;
	return 0;
}