// Crt. 2019-12-17  10:14:31
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 300005
#define PII pair<int, int>
using namespace std;

int n, m, sum[N];
PII s[N];

inline void add(int p, int w) {
    while (p <= m) sum[p] += w, p += p & (-p);
}

inline int ask(int p) {
    int res = 0;
    while (p) res += sum[p], p -= p & (-p);
    return res;
}

bool cmp(PII a, PII b) { return a.second + b.first < b.second + a.first; }

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &s[i].first, &s[i].second);

    sort(s + 1, s + n + 1, cmp);

    for (int i = 1, pos = 0; i <= m; ++i) {
        while (pos < n && s[pos + 1].second - s[pos + 1].first + 1 <= i)
            ++pos, add(s[pos].first, 1), add(s[pos].second + 1, -1);
        long long ans = n - pos;
        for (int j = i; j <= m; j += i)
            ans += ask(j);
        printf("%lld\n", ans);
    }


    return 0;
}
