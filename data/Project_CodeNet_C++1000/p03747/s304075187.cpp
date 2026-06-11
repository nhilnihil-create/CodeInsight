#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

#define Rep(i,l,r) for (int i = (l); i <= (r); ++ i)
#define RepD(i,r,l) for (int i = (r); i >= (l); -- i)
#define RepG(i,x) for (int i = hd[x]; i; i = e[i].nxt)

const int N = 200005;
int a[N], x, w, n, l, t, pos = 0;

int main () {
	scanf ("%d%d%d", &n, &l, &t);
	Rep(i,1,n) {
		scanf ("%d%d", &x, &w);
		if (w==1) a[i] = (x+t)%l, pos = pos+(x+t)/l;
		else a[i] = ((x-t)%l+l)%l, pos = pos+(x-t)/l-(x<t&&(x-t)%l);
	}
	sort (a+1, a+n+1); pos = (pos%n+n)%n+1;
	Rep(i,pos,n) printf ("%d\n", a[i]);
	Rep(i,1,pos-1) printf ("%d\n", a[i]);
	return 0;
}
