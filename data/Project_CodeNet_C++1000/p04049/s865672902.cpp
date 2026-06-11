#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T> inline void getint(T &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, K, ans = 0x3f3f3f3f, dis[2005], tope = 0;
struct Edge {int np; Edge *nxt;} E[4005], *V[2005];
struct edge {int u, v;} ed[2005];

inline void addedge(const int &u, const int &v){
	E[++tope].np = v, E[tope].nxt = V[u], V[u] = E + tope;
}

void dfs(const int &u, const int &fa){
	for(register Edge *ne = V[u]; ne; ne = ne->nxt)
		if(ne->np != fa) dis[ne->np] = dis[u] + 1, dfs(ne->np, u);
}

int main(){
	getint(N), getint(K);
	for(register int i = 1; i < N; i++){
		getint(ed[i].u), getint(ed[i].v);
		addedge(ed[i].u, ed[i].v), addedge(ed[i].v, ed[i].u);
	}
	if(K & 1){
		for(register int i = 1; i < N; i++){
			dis[ed[i].u] = 0, dfs(ed[i].u, ed[i].v);
			dis[ed[i].v] = 0, dfs(ed[i].v, ed[i].u); int res = 0;
			for(register int j = 1; j <= N; j++) if(dis[j] > (K >> 1)) res++;
			ans = min(ans, res);
		}
	}
	else{
		for(register int i = 1; i <= N; i++){
			dis[i] = 0, dfs(i, 0); int res = 0;
			for(register int j = 1; j <= N; j++) if(dis[j] > (K >> 1)) res++;
			ans = min(ans, res);
		}
	}
	return printf("%d\n", ans), 0;
}