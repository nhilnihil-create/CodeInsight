#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int ans, n, k, fa[MAXN]; vector <int> to[MAXN];

int dfs(int x){
	int r = 0;
	for(auto v: to[x])
		r = max(r, dfs(v));
	if((++ r) == k && fa[x] != 1) ++ ans, r = 0;
	return r;
}
int main(){
	int i;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &fa[i]);
		if(i > 1) to[fa[i]].push_back(i);
	} if(fa[1] != 1) ++ ans, fa[1] = 1;
	dfs(1), printf("%d\n", ans);
	return 0;
}