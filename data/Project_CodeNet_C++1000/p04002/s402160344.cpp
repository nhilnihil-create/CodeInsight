#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int n;
int a[N], b[N];
LL h, w;
LL res[10];
map<PII, bool> hm;

inline int F(int x, int y) {
    return hm[mp(x, y)];
}

int main() {
    scanf("%lld%lld%d", &h, &w, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        hm[mp(a[i], b[i])] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i], y = b[i];
        if (x + 2 <= h) {
            if (y + 2 <= w) ++res[F(x, y) + F(x + 1, y) + F(x + 2, y) + F(x, y + 1) + F(x + 1, y + 1) + F(x + 2, y + 1) + F(x, y + 2) + F(x + 1, y + 2) + F(x + 2, y + 2)];
            if (1 <= y - 1 && y + 1 <= w) ++res[F(x, y - 1) + F(x + 1, y - 1) + F(x + 2, y - 1) + F(x, y) + F(x + 1, y) + F(x + 2, y) + F(x, y + 1) + F(x + 1, y + 1) + F(x + 2, y + 1)];
            if (1 <= y - 2) ++res[F(x, y - 2) + F(x + 1, y - 2) + F(x + 2, y - 2) + F(x, y - 1) + F(x + 1, y - 1) + F(x + 2, y - 1) + F(x, y) + F(x + 1, y) + F(x + 2, y)];
        }
        if (1 <= x - 1 && x + 1 <= h) {
            if (y + 2 <= w) ++res[F(x - 1, y) + F(x, y) + F(x + 1, y) + F(x - 1, y + 1) + F(x, y + 1) + F(x + 1, y + 1) + F(x - 1, y + 2) + F(x, y + 2) + F(x + 1, y + 2)];
            if (1 <= y - 1 && y + 1 <= w) ++res[F(x - 1, y - 1) + F(x, y - 1) + F(x + 1, y - 1) + F(x - 1, y) + F(x, y) + F(x + 1, y) + F(x - 1, y + 1) + F(x, y + 1) + F(x + 1, y + 1)];
            if (1 <= y - 2) ++res[F(x - 1, y - 2) + F(x, y - 2) + F(x + 1, y - 2) + F(x - 1, y - 1) + F(x, y - 1) + F(x + 1, y - 1) + F(x - 1, y) + F(x, y) + F(x + 1, y)];
        }
        if (1 <= x - 2) {
            if (y + 2 <= w) ++res[F(x - 2, y) + F(x - 1, y) + F(x, y) + F(x - 2, y + 1) + F(x - 1, y + 1) + F(x, y + 1) + F(x - 2, y + 2) + F(x - 1, y + 2) + F(x, y + 2)];
            if (1 <= y - 1 && y + 1 <= w) ++res[F(x - 2, y - 1) + F(x - 1, y - 1) + F(x, y - 1) + F(x - 2, y) + F(x - 1, y) + F(x, y) + F(x - 2, y + 1) + F(x - 1, y + 1) + F(x, y + 1)];
            if (1 <= y - 2) ++res[F(x - 2, y - 2) + F(x - 1, y - 2) + F(x, y - 2) + F(x - 2, y - 1) + F(x - 1, y - 1) + F(x, y - 1) + F(x - 2, y) + F(x - 1, y) + F(x, y)];
        }

    }
    LL sum = 0;
    for (int i = 1; i <= 9; ++i)
        sum += (res[i] /= i);
    res[0] = (h - 2) * (w - 2) - sum;
    for (int i = 0; i <= 9; ++i)
        printf("%lld\n", res[i]);
    return 0;
}