#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 100005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int n,a[MAXN],f[MAXN],deg[MAXN];
struct edge{
	int v,nxt;
}e[MAXN << 1];
int top = 1,head[MAXN];
void Add_Edge (int u,int v){
	e[++ top] = edge {v,head[u]};head[u] = top;
	e[++ top] = edge {u,head[v]};head[v] = top;
}

bool dfs (int u,int fa){
	if (deg[u] == 1) return f[u] = a[u],1;
	f[u] = 2 * a[u];int Maxn = 0;
	for (Int i = head[u];i;i = e[i].nxt){
		int v = e[i].v;
		if (v == fa) continue;
		if (!dfs (v,u)) return 0;
		f[u] -= f[v],Maxn = max (Maxn,f[v]);
	}
	if (0 <= f[u] && f[u] <= a[u] && Maxn <= a[u]) return 1;
	else return 0;
}

signed main(){
	read (n);
	for (Int i = 1;i <= n;++ i) read (a[i]);
	for (Int i = 2,u,v;i <= n;++ i) read (u,v),Add_Edge (u,v),deg[u] ++,deg[v] ++;
	if (n == 2) return puts (a[1] == a[2] ? "YES" : "NO"),0;
	for (Int i = 1;i <= n;++ i) if (deg[i] > 1) return puts (dfs (i,0) && !f[i] ? "YES" : "NO"),0;
	return 0;
} 