#include "bits/stdc++.h"
using namespace std;
int n, k;
int a[100010];
vector <int> g[100010];
int dep[100010];
int ans;

void dfs(int x) {
	dep[x] = 1;
	for(auto i : g[x]) {
		dfs(i);
		dep[x] = max(dep[x], 1 + dep[i]);
	}
	if(dep[x] == k && x > 1 && a[x] != 1) {
		++ans;
		dep[x] = -n;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(a[1] != 1) {
		a[1] = 1;
		++ans;
	} 
	for(int i = 2; i <= n; i++) {
		g[a[i]].push_back(i);
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}