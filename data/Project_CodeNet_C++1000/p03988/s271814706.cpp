// Crt. 2019-12-17  19:57:45
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 104
using namespace std;

int n, a[N], num[N];

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int mi = (a[1] + 1) / 2;
    num[mi] = a[1] % 2 + 1;
    for (int i = a[1]; i > mi; --i)
        num[i] = 2;

    for (int i = 1; i <= n; ++i)
        --num[a[i]];

    for (int i = a[1]; i >= mi; --i)
        if (num[i] > 0) return puts("Impossible"), 0;

    for (int i = 1; i <= mi; ++i)
        if (num[i] < 0) return puts("Impossible"), 0;

    puts("Possible");

    return 0;
}
