#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x": " << x << endl;
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

LL a[N];
LL b[N];
int bits[N];

inline void update(int pos) {
    for (; pos < N; pos += lowbit(pos))
        bits[pos]++;
}
inline int query(int pos) {
    int res = 0;
    for (; pos; pos -= lowbit(pos))
        res += bits[pos];
    return res;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // purple_bro
    int n, k;

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] -= k;
        a[i] += a[i - 1];
        b[i] = a[i];
    }

    b[n + 1] = 0;
    sort(b + 1, b + 1 + n + 1);
    int tot = unique(b + 1, b + 1 + n + 1) - b - 1;

    int pos = lower_bound(b + 1, b + 1 + tot, 0) - b;
    update(pos);

    LL ans = 0;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
        ans += query(pos);
        update(pos);
    }

    printf("%lld\n", ans);

    return 0;
}
