#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x": " << x << endl;
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
const int N = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

priority_queue<int> Q;
int a[N];
LL pre[N];
LL suf[N];

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // purple_bro
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n * 3; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n * 2; i++) {
        if (i <= n) {
            pre[i] = pre[i - 1] + a[i];
            Q.push(-a[i]);
        } else {
            Q.push(-a[i]);
            pre[i] = pre[i - 1] + a[i];
            pre[i] -= -Q.top();
            Q.pop();
        }
    }

    for (;!Q.empty();)
        Q.pop();

    for (int i = n * 3; i >= n + 1; i--) {
        if (i > 2 * n) {
            suf[i] = suf[i + 1] + a[i];
            Q.push(a[i]);
        } else {
            Q.push(a[i]);
            suf[i] = suf[i + 1] + a[i];
            suf[i] -= Q.top();
            Q.pop();
        }
    }

    LL ans = -INF;

    for (int i = n; i <= 2 * n; i++)
        ans = max(ans, pre[i] - suf[i + 1]);

    printf("%lld\n", ans);

    return 0;
}
