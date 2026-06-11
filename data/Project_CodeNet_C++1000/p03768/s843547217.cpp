#include<iostream>
#include<cstdio>

const int SIZE = 100000 + 7;

using namespace std;

struct query{
	int d, v, c;
}que[SIZE];

int f[SIZE][14];
int head[SIZE], ver[SIZE * 2], nxt[SIZE * 2];
int N, M, Q, tot = 1;

inline void add(const int &u, const int &v) {
	ver[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

inline void BFS(const int &s, const int &d, const int &c) {
	f[s][d] = c;
	if( !d ) return;
	
	if(!f[s][d - 1]) BFS(s, d - 1, c);
	for(int i = head[s]; i; i = nxt[i]) {
		int v = ver[i];
		if(!f[v][d - 1]) BFS(v, d - 1, c);
	}
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= M; ++i) {
		int a, b; scanf("%d%d",&a,&b);
		add(a, b); add(b, a);
	}
	scanf("%d",&Q);
	for(int i = Q; i >= 1; --i)
		scanf("%d%d%d",&que[i].v,&que[i].d,&que[i].c);
	for(int i = 1; i <= Q; ++i)
		if(!f[que[i].v][que[i].d]) BFS(que[i].v, que[i].d, que[i].c);
	for(int i = 1; i <= N; ++i)
		printf("%d\n",f[i][0]);
	return 0;
}