#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define pb push_back

using namespace std;

const int N = 100010;

vector<int> G[N];
int fa[N], sz[N];
int n, m;

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int col[N];

bool DFS(int o){
	for(int v : G[o]){
		if(!col[v]){
			col[v] = 3 - col[o];
			if(!DFS(v)) return false;
		}
		else if(col[v] == col[o]) return false;
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	For(i, 1, n) fa[i] = i, sz[i] = 1;
	For(i, 1, m){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v), G[v].pb(u);
		u = find(u), v = find(v);
		if(u ^ v) fa[u] = v, sz[v] += sz[u];
	}
	
	int ct = n, blk = 0, blk2 = 0;
	For(i, 1, n) if(fa[i] == i){
		col[i] = 1;
		if(sz[i] == 1) --ct;
		else{
			++blk;
			if(DFS(i)) ++blk2; 
		}
	}

	printf("%lld\n", 1ll * n * n - 1ll * ct * ct + 1ll * blk * blk + 1ll * blk2 * blk2);
	return 0;
}