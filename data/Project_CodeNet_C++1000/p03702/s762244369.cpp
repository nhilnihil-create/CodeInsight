#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x": " << x << endl;
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

LL h[N];
int n, a, b;

bool check(LL times) {
    LL k = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] <= times * b)
            continue;
        else {
            LL t = h[i] - times * b;
            LL p = a - b;
            k += t / p + (t % p != 0);
        }
    }
    return k <= times;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // purple_bro
    scanf("%d%d%d", &n, &a, &b);

    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i]);

    LL res = -1, L = 1, R = 1e9 + 1;

    for (;L <= R;) {
        LL mid = L + R >> 1;
        if (check(mid)) {
            res = mid;
            R = mid - 1;
        } else
            L = mid + 1;
    }

    printf("%lld\n", res);

    return 0;
}
