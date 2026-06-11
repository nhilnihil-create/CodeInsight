#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
inline char nc() {
//	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
const int maxn = 1e5 + 5;
int n;
int f[maxn];
	int head[maxn];
vector<int> rec[maxn];
struct edge {
	int to, nex;
	edge(int to=0,int nex=0):to(to),nex(nex){} 
};
vector<edge> G;
inline void addedge(int u, int v) {
	G.push_back(edge(v, head[u])), head[u] = G.size() - 1;
}
void dfs(int u) {
	for(int i = head[u]; ~i; i = G[i].nex) {
		int v = G[i].to;
		dfs(v);
		rec[u].push_back(f[v]);
	}
	sort(rec[u].begin(), rec[u].end());
	for(unsigned int i = 0; i < rec[u].size(); ++i) {
		f[u] = max(f[u], rec[u][i]) + 1;
	}
}
int main() {
	read(n);
	memset(head, -1, sizeof(head));
	for(int i = 2; i <= n; ++i) {
		int fa; read(fa);
		addedge(fa, i);
	}
	dfs(1);
	printf("%d\n", f[1]);
	return 0;
} 