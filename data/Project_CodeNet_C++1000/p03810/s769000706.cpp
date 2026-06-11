// Crt. 2019-12-09  21:17:27
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

int n, a[N];

inline int check() {
    int sum[2], tmp = 0;
    long long s = 0;
    sum[0] = sum[1] = 0;
    for (int i = 1; i <= n; ++i)
        sum[a[i] % 2]++, tmp += a[i] == 1, s += a[i];
    if (tmp) return (s - n) % 2 ? 1 : 2;
    if (sum[0] % 2 == 0 && sum[1] == 1) return 0;
    if (sum[0] % 2 == 1 && sum[1] >= 1) return 1; 
    if (sum[0] % 2 == 0 && (sum[1] >= 2 || !sum[1])) return 2;
    return -1;
}

inline void operates() {
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2) --a[i];
    int g = a[1];
    for (int i = 2; i <= n; ++i)
        g = __gcd(g, a[i]);
    for (int i = 1; i <= n; ++i)
        a[i] /= g;
}

bool dfs() {
    int tmp = 0;
    if (tmp = check()) return (tmp == 1);
    return operates(), !dfs();
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    puts(dfs() ? "First" : "Second");

    return 0;
}
