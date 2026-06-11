#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int father[N], dep[N], mx[N], k, ans;
vector<int > p[N];

void dfs(int x, int fa){
	dep[x] = dep[fa] + 1; mx[x] = dep[x]; 
	for (int v : p[x]){
		dfs(v, x);
		mx[x] = max(mx[x], mx[v]);
	}
	if (x != 1 && mx[x] > k + 1 && mx[x] - dep[x] == k - 1) {ans ++; mx[x] = 0; }
}

int main(){
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &father[i]);
		if (i != 1) p[father[i]].push_back(i);
	}
	ans = (father[1] != 1);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}