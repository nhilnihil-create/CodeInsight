#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
#define int long long
int flag = 0;
int a[100005];
vector <int> G[100005];
void dfs (int x, int fa) {
	if (G[x].size() == 1) return ;
	int sum = 0, _max = 0;
	for (int i = 0; i < G[x].size(); i++) {
		int y = G[x][i];
		if (y == fa) continue;
		dfs (y, x);
		sum += a[y];
		_max = max (_max, a[y]);
	}
	int left;
	if (_max > sum - _max) left = sum - _max;
	else left = sum / 2;
	if (sum < a[x]) {
		flag = 1;
		return ;
	}
	if (sum - a[x] > left) {
		flag = 1;
		return ;
	}
	a[x] = 2 * a[x] - sum;
}
int in[100005];
signed main () {
	int n;
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf ("%lld %lld", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		in[x]++, in[y]++; 
	}
	if (n == 2) {
		if (a[1] == a[2]) printf ("YES");
		else printf ("NO");
		return 0;
	}
	int root = 1;
	while (in[root] == 1 && root < n) root++;
	dfs (root, 0);
	if (flag == 1 || a[root] != 0) printf ("NO");
	else printf ("YES");
	return 0;
}