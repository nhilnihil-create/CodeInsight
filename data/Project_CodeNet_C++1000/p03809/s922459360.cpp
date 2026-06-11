#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#define rep(i,j,k) for(register int i = j; i <= k; i++) 
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define fi first
#define se second
//#define P pair<ull,ull>
//#define PP pair<int,pair<int,int> >
//#define mp(a,b) make_pair(a,b)
#define ll long long
#define ull unsigned long long
using namespace std;
 
inline int read() { 
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;
}

const int N = 1e5+5;
struct edge{ int to, nxt; } e[N<<1];
int deg[N], head[N], cnt = 0, a[N], f[N];
inline void add(int x,int y) { 
	deg[x]++, deg[y]++;
	e[++cnt].to = y, e[cnt].nxt = head[x], head[x] = cnt;
	e[++cnt].to = x, e[cnt].nxt = head[y], head[y] = cnt;
}

#define ez(i,j) for(register int i = head[j]; i; i=e[i].nxt)
#define to e[i].to
inline void out() { puts("NO"), exit(0); }
inline void dfs(int x,int fa) { 
	if( deg[x] == 1 ) { f[x] = a[x]; return; }
	ll sum = 0, t, y; int maxl = 0;
	ez(i,x) if( to != fa ) { 
		dfs(to,x);
		sum += f[to];
		maxl = max(maxl,f[to]);
	}
	if( sum < a[x] ) out(); 
	if( sum > a[x] ) { 
		t = sum - a[x];
		if( maxl > sum / 2 ) y = sum - maxl;
		else y = sum / 2;
		
		if( t > y ) out();
		f[x] = sum - t * 2;
	} else f[x] = sum;
}

int main() {
	int n = read(), rt = 0;
	if( n == 2 ) { 
		if( read() == read() ) puts("YES");
		else puts("NO");
		return 0;
	}
	rep(i,1,n) a[i] = read();
	rep(i,1,n-1) add(read(),read());
	rep(i,1,n) if( deg[i] > 1 ) { rt = i; break; }
	
	dfs(rt,0);
	if( !f[rt] ) puts("YES");
	else puts("NO");
	return 0; 
}