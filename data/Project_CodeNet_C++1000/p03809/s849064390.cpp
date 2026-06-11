#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define pb push_back

using namespace std;

const int N = 100010;

typedef long long LL;

int n;
LL val[N], up[N];
vector<int> G[N];

int deg[N];

void DFS(int o, int f){
	if(deg[o] == 1){
		up[o] = val[o];
		return;
	}
	LL mx = 0, sum = 0;
	for(int v : G[o]){
		if(v == f) continue;
		DFS(v, o);
		sum += up[v];
		mx = max(mx, up[v]);
	}
	LL x = sum - val[o];
	//printf("%d: %d %lld %lld %lld\n", o, x, sum, val[o], mx);
	up[o] = sum - 2 * x;
	if(x > sum - mx || x < 0 || up[o] < 0){
		puts("NO");
		exit(0);
	}
}

int main(){
	scanf("%d", &n);
	For(i, 1, n) scanf("%lld", &val[i]);
	For(i, 2, n){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v), G[v].pb(u);
		++deg[u], ++deg[v];
	}
	if(n == 2){
		puts(val[1] == val[2] ? "YES" : "NO");
		return 0;
	}
	int root = 0;
	For(i, 1, n) if(deg[i] ^ 1){
		root = i;
		break;
	}
	DFS(root, 0);
	puts(up[root] ? "NO" : "YES");
	return 0;
}