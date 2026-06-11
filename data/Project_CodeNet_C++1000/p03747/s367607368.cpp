#include <bits/stdc++.h>
#define newline printf ("\n")
#define space printf (" ")
#define cinfalse ios::sync_with_stdio(false)
#define fread(a) freopen (a".in", "r", stdin), freopen(a".out", "w", stdout)
#define rint register int
#define For(i, a, b) for (rint i = a; i <= b; i ++)
#define Low(i, a, b) for (rint i = a; i >= b; i --)
#define FFr(i, a, b, c) for (rint i = a; i <= b; i += c)
#define FLw(i, a, b, c) for (rint i = a; i >= b; i -= c)
#define min(a, b) ((a)>(b)?(b):(a))
#define max(a, b) ((a)>(b)?(a):(b))
#define ll long long
#define MAXN 100005
using namespace std;

ll c;
int x[MAXN], xx[MAXN], w[MAXN];
int l, r, s, t, n, m;
int main()
{
	scanf ("%d%d%d", &n, &l, &t);
	for (rint i = 1; i <= n; i ++) scanf ("%d%d", &x[i], &w[i]);
	for (rint i = 1; i <= n; i ++)
	{
		if (w[i] == 2) w[i] -= 3;
		r = x[i]+w[i]*t;	
		if (r > 0) c += r/l, c %= n;
        else if (r<0) c += (r+1)/l-1, c %= n;
		xx[i]=(r%l+l)%l;
	}
	sort (xx+1, xx+n+1);
	c = (c+n)%n;
	for (rint i = c+1; i <= n; i ++) printf ("%d\n", xx[i]);
	for (rint i = 1; i <= c; i ++) printf ("%d\n", xx[i]);
    return 0;
}
