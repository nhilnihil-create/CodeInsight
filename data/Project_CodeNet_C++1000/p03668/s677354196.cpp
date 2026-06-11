#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];
int n, sg[N];

void DFS(int o, int f){
	for(int v : G[o]){
		if(v == f) continue;
		DFS(v, o);
		sg[o] ^= sg[v] + 1;
	}
}

int main(){
	scanf("%d", &n);
	For(i, 2, n){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v), G[v].pb(u);
	}
	DFS(1, 0);
	puts(sg[1] ? "Alice" : "Bob");
	return 0;
}