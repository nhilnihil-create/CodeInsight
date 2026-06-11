# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, d, x, y, i, j;
	char ch[5] = "YBGR";
    scanf("%d%d%d", &n, &m, &d);
    for (i = 1; i <= n; ++i, putchar('\n'))
        for (j = 1; j <= m; ++j) printf("%c", ch[2 * ((i + j + m) / d % 2) + (i - j + m) / d % 2]);
	return 0;
}