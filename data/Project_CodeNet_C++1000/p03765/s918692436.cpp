#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, pre1[maxn][20], pre2[maxn][20];
char s[maxn], t[maxn];

int merge(int x, int y) {
    if (x == -1 || y == -1) return ~x ? x : y;
    if (!x && !y) return 1;
    if (x && y) return 0;
    return -1;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        pre1[i][0] = s[i] == 'B';
    }
    for (int i = 1; i <= m; i++) {
        pre2[i][0] = t[i] == 'B';
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            pre1[j][i] = merge(pre1[j][i - 1], pre1[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= m; j++) {
            pre2[j][i] = merge(pre2[j][i - 1], pre2[j + (1 << (i - 1))][i - 1]);
        }
    }
    scanf("%d", &q);
    for (int i = 1, a, b, c, d; i <= q; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int s1 = -1, s2 = -1;
        for (int j = 19; ~j; j--) if (a + (1 << j) - 1 <= b) {
            s1 = merge(s1, pre1[a][j]), a += (1 << j);
        }
        for (int j = 19; ~j; j--) if (c + (1 << j) - 1 <= d) {
            s2 = merge(s2, pre2[c][j]), c += (1 << j);
        }
        printf("%s\n", s1 == s2 ? "YES" : "NO");
    }
    return 0;
}