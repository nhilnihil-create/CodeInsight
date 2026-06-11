//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define N 100005
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

int n , a[N] , l , q , f[N][33] , ans ;
int main ()
{
//    freopen (".in" , "r" , stdin) ; freopen (".out" , "w" , stdout) ;
	n = read () ;
	for (int i = 1 ; i <= n ; i ++) a[i] = read () ;
	l = read () ; q = read () ;
	for (int i = 1 ; i <= n ; i ++)
	{
		f[i][0] = upper_bound (a + 1 , a + n + 1 , a[i] + l) - a - 1 ;
	}
	for (int j = 1 ; j <= 30 ; j ++)
		for (int i = 1 ; i <= n ; i ++)
			f[i][j] = f[f[i][j - 1]][j - 1] ;
	while (q --> 0)
	{
		int x = read () , y = read () ;
		if (x > y) swap (x , y) ;
		int tmp = x ;
		for (int i = 30 ; i >= 0 ; i --)
		{
			if (f[tmp][i] < y)
			{
				ans += (1 << i) ;
				tmp = f[tmp][i] ;
			}
		}
		cout << ans + 1 << "\n" ;
		ans = 0 ;
	}
}


