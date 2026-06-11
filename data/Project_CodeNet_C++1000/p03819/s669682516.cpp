#include <bits/stdc++.h>
#define Pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 7;
inline int R()
{
    int rt = 0; char ch = getchar(); bool isn = false;
    for ( ; ch < '0' || ch > '9'; ch = getchar() ) isn = ch == '-' ? true : isn;
    for ( ; ch >= '0' && ch <= '9'; ch = getchar() ) rt = rt * 10 + ch - '0';
    return isn ? -rt : rt;
}

int n, m;
struct Iv { int l, r; }a[MAXN];
inline bool Cmp ( Iv t1, Iv t2 ) { return t1.r - t1.l < t2.r - t2.l; }

int t[MAXN], ans[MAXN];
void Add ( int pos, int val )
{
	for ( ; pos <= m; pos += ( pos & -pos ) )
		t[pos] += val;
}

int Query ( int pos )
{
	int rt = 0;
	for ( ; pos; pos -= ( pos & -pos ) )
		rt += t[pos];
	return rt;
}

int main()
{
	n = R(), m = R();
	for ( int i = 1; i <= n; ++i )
		a[i].l = R(), a[i].r = R(), ++ans[a[i].r - a[i].l + 1];
	sort ( a + 1, a + n + 1, Cmp );
	int na = 1;
	for ( int i = m; i; --i )
		ans[i] += ans[i + 1];
	for ( int i = 1; i <= m; ++i )
	{
		for ( ; na <= n && a[na].r - a[na].l + 1 < i; ++na )
			Add ( a[na].l, 1 ), Add ( a[na].r + 1, -1 );
		for ( int j = 0; j <= m; j += i )
			ans[i] += Query ( j );
		printf ( "%d\n", ans[i] );
	}
	return 0;
}