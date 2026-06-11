#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char s[N][N];
int main() {
	int n, m, d;
	char ch[5] = "RGBY";
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			int x = (i + j) / d % 2 * 2 + (i + m - j) / d % 2;
			putchar(ch[x]);
			s[i][j] = ch[x];
		}
		puts("");
	}
	/*for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			for (int k = 1; k <= n; ++ k) {
				for (int l = 1; l <= m; ++ l) {
					if (abs(i - k) + abs(j - l) == d && s[i][j] == s[k][l]) assert(0);
				}
			}
		}
	}*/
}

