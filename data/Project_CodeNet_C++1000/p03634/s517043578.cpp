#include <bits/stdc++.h>
using namespace std;

struct node{
	int u, v, w, next;
	node(){}
	node(int _u, int _v, int _w, int _next){
		u = _u;
		v = _v;
		w = _w;
		next = _next;
	}
}Edge[333333];

int Count, head[333333];

int n;
int q, k, a, b, u, v, w;
bool vis[111111];
long long dis[111111];

void AddEdge(int u, int v, int w){
	Count++;
	Edge[Count] = node(u, v, w, head[u]);
	head[u] = Count;
}

void dfs(int x){
	vis[x] = 1;
	for(int i = head[x]; i; i = Edge[i].next){
		int v = Edge[i].v;
		if(vis[v]) continue;
		dis[v] = dis[x] + Edge[i].w;
		dfs(v);
	}
}

int main(){
	scanf("%d", &n);
	for(int k = 1; k < n; k++){
		scanf("%d%d%d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
		
	scanf("%d%d", &q, &k);
	dfs(k);
	while(q--){
		scanf("%d%d", &a, &b);
		printf("%lld\n", dis[a] + dis[b]);
	}
	return 0;
}