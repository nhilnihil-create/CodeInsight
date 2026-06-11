#include <bits/stdc++.h>
#define N 100005
#define int long long
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1 == p2)?EOF:*p1++)
using namespace std ;
//char buf[(1 << 22)] , *p1 = buf , *p2 = buf ;
inline int read ()
{
    char c = getchar () ; int x = 0 , f = 1 ;
    while (c < '0' || c > '9') { if (c == '-') f = -1 ; c = getchar () ; }
    while (c >= '0' && c <= '9'){ x = x * 10 + c - '0' ; c = getchar () ; }
    return x * f ;
}
int n , m , ver[N << 1] , nxt[N << 1] , hed[N] , tot , ans[N] , Dis[N] ;
struct as {
	int v , d , c ;
} a[N] ;
void add (int x , int y) { ver[++ tot] = y ; nxt[tot] = hed[x] ; hed[x] = tot ; }
void dfs (int x , int col , int dis)
{
	if (! ans[x]) ans[x] = col ;
	if (! dis || Dis[x] >= dis) return ;
	Dis[x] = dis ;
	for (int i = hed[x] ; i ; i = nxt[i])
	{
		int y = ver[i] ;
		dfs (y , col , dis - 1) ;
	}
}
signed main ()
{
	n = read () , m = read () ;
	for (int i = 1 , u , v ; i <= m ; u = read () , v = read () , add (u , v) , add (v , u) , i ++) ;
	int q = read () ;
	for (int i = 1 ; i <= q ; i ++) a[i].v = read () , a[i].d = read () , a[i].c = read () ;
	for (int i = q ; i >= 1 ; i --) dfs (a[i].v , a[i].c , a[i].d) ;
	for (int i = 1 ; i <= n ; i ++) printf ("%d\n" , ans[i]) ;
} 
/*
7 7
1 2
1 3
1 4
4 5	
5 6
5 7
2 3
2
6 1 1
1 2 2
*/