#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cctype>
#include <ctime>
#include <bitset>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x7fffffff;
int n, m, d, x, y;
char s[] = {'B', 'G', 'Y', 'R'};

int main() {
#ifdef __AiR_H
    freopen("B.in", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif // __AiR_H
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            x = (i + j - 1) / d; y = (n - i + j) / d;
            if (x % 2 == 1) {
                if (y % 2 == 1) { printf("%c", s[0]); } else { printf("%c", s[1]); }
            } else {
                if (y % 2 == 1) { printf("%c", s[2]); } else { printf("%c", s[3]); }
            }
        }
        printf("\n");
    }
#ifdef __AiR_H
    printf("Time used = %.2fs\n", (double)clock() / CLOCKS_PER_SEC);
#endif // __AiR_H
    return 0;
}
