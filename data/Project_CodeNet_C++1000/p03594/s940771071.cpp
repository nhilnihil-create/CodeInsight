#include <cstdio>
using namespace std;
const char COLORS[] = "RYGB";
int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            int x = (i + m - j) / d % 2;
            int y = (i + j) / d % 2;
            putchar(COLORS[x * 2 + y]);
        }
        puts("");
    }
    return 0;
}