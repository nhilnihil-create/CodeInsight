#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

const int kN = 500 + 5;
int n, m, d;
int a[kN][kN];

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    int mod = d + d;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            int x = (i + j) % mod;
            int y = ((i - j) % mod + mod) % mod;
            putchar("RGBY"[(x < d) * 2 + (y < d)]);
        }
        puts("");
    }

}