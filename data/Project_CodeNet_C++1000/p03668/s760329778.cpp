#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200050;

int head[N], to[N], nex[N], tot, sg[N], n;
void addedge(int u, int v){
	tot ++; to[tot] = v, nex[tot] = head[u], head[u] = tot;
	tot ++; to[tot] = u, nex[tot] = head[v], head[v] = tot;
}
void dfs(int x, int fa){
	for(int i = head[x]; i; i = nex[i]){
		if(to[i] != fa){
			dfs(to[i], x);
			sg[x] ^= sg[to[i]] + 1;
		}
	}
}
inline void gi(int &x){
	x = 0; char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
}

int main()
{
	int i, j, k;
	for(gi(n), i = 1; i < n; i ++)
		gi(j), gi(k), addedge(j, k);
	dfs(1, 0); puts(sg[1] ? "Alice" : "Bob");
	
	return 0;
}
