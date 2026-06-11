#include<bits/stdc++.h>
using namespace std;
#define C getchar()
inline int read() {
	int num = 0;
	char c = C;
	for(;c<'0' || c>'9';c=C);
	for(;c>='0' && c<='9';c=C) num = (num << 1) + (num << 3) + (c ^ 48);
	return num;
}

//int nxt[200010],head[100010],to[200010],tot;
//
//inline void add(int x,int y) {
//	nxt[++tot] = head[x],head[x] = tot,to[tot] = y;
//}

int vis[100010][12];

vector<int> edge[100010];

inline void putc(int x,int d,int cl) {
	if (d == -1) return ;
	if (vis[x][d]) return ;
	vis[x][d] = cl;
	for(int i=0;i<edge[x].size();++i) putc(edge[x][i] , d - 1 , cl);
}

int n,m,Q;
struct node {
	int rt,d,cl;
}a[100010];

int main() {
//	freopen("1.in","r",stdin);
//	freopen("d.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=m;++i) {
		int u = read(),v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
//		add(u , v);add(v , u);
	}
//	for(int i=1;i<=n;++i) add(i , i);
  for(int i=1;i<=n;++i) edge[i].push_back(i);
	
	Q = read();
	for(int i=1;i<=Q;++i) a[i].rt = read(),a[i].d = read(),a[i].cl = read();
	for(int i=Q;i>=1;--i) putc(a[i].rt , a[i].d , a[i].cl);
	for(int i=1;i<=n;++i) printf("%d\n",vis[i][0]);
	return 0;
}