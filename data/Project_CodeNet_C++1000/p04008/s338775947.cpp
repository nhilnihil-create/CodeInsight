/*input
8 2
4 1 2 3 1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0, c = getchar();
	for(; !(c > 47 && c < 58); c = getchar());
	for(; (c > 47 && c < 58); c = getchar()) x = x * 10 + c - 48;
	return x;
}

const int N = 100005;
vector<int> G[N];
int a[N], n, k;

int ans = 0;

int dfs(int u) {
	int cur = 0;
	for(int v : G[u]) {
		int x = dfs(v);
		if(u > 1) {
			if(k - 1 == x) ++ ans;
				else cur = max(cur, x + 1);
		}
	}
	return cur;
}

int main(){
	n = read(), k = read();
	for(int i = 1; i <= n; a[i ++] = read());
	for(int i = 2; i <= n; ++ i) G[a[i]].emplace_back(i);

	dfs(1);
	printf("%d\n", ans + (a[1] > 1));
}