#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[100010];
int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	reverse (a + 1, a + n + 1);
	int x; for (x = 1; a[x] >= x; x++); x--;
	if ((a[x] - x) & 1) { printf ("First\n"); return 0; }
	int t; for (t = x; t <= n && a[t] >= x; t++); t--;
	if ((t - x) & 1) printf ("First\n");
	else printf ("Second\n");
	return 0;
}