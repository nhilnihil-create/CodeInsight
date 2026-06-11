#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
char s[N], t[N];
int n, m, q, cnts[N][2], cntt[N][2];
void can(int sa, int sb, int ta, int tb) {
	if (sa > ta) swap(tb, sb), swap(ta, sa);
	int mn = min(ta - sa, tb - sb); 
	ta -= mn, tb -= mn;
	puts(abs(tb - sb + ta - sa) % 3 == 0 ? "YES" : "NO");
}
int main() {
    scanf ("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 2; ++j)
            cnts[i][j] = cnts[i - 1][j] + (j + 'A' == s[i]);
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < 2; ++j)
            cntt[i][j] = cntt[i - 1][j] + (j + 'A' == t[i]);
    scanf ("%d", &q);
    while (q--) {
        int a, b, c, d;
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        int sa = cnts[b][0] - cnts[a - 1][0], sb = (b-a+1) - sa;
        int ta = cntt[d][0] - cntt[c - 1][0], tb = (d-c+1) - ta;
        // (sa, sb) -> (ta, tb)
    //    if (sa > ta) swap(ta, sa), swap(tb, sb);'
        can(sa, sb, ta, tb);
    }
    return 0; 
}