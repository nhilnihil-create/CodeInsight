//Created Time:2019年12月19日 星期四 21时02分54秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 100005

using namespace std;

int n;
int val[N];

vector < int > G[N];

void dfs(int ,int);

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", val + i);
	for(int i = 1; i < n; ++i){
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v); G[v].push_back(u);
	}
	if(n == 2){
		if(val[1] != val[2]) puts("NO");
		else puts("YES");
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		if(G[i].size() == 1) continue;
		dfs(i, 0);
		if(val[i]) puts("NO");
		else puts("YES");
		return 0;
	}
	return 0;
}

void dfs(int u, int fa){
	int sz = G[u].size(), mx = 0; long long sum = 0;
	if(sz == 1) return ;
	for(int i = 0; i < sz; ++i){
		int v = G[u][i]; if(v == fa) continue;
		dfs(v, u); sum += val[v];  mx = max(mx, val[v]);
	}
	if(sum < val[u] || val[u] * 2 < sum || mx > val[u]){ puts("NO"); exit(0); }
	long long x = sum - val[u];  val[u] -= x;
	return ;
}
