// Crt. 2020-01-07  16:43:40
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
using namespace std;
typedef long long ll;

int n, a[N];
ll sum[N], asum[N];

inline int Abs(int x) {
    return x < 0 ? -x : x;
}

int main(){
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;

    scanf("%d", a + 1);
    for (int i = 2; i <= n; ++i) {
        char pos;
        scanf(" %c %d", &pos, a + i);
        if (pos == '-') a[i] *= -1;
    }

    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    for (int i = n; i >= 1; --i)
        asum[i] = asum[i + 1] + Abs(a[i]);

    ll ans = sum[n];
    for (int i = 2, j; i <= n; ++i) {
        if (a[i] > 0) continue;
        for (j = i; j < n && a[j + 1] > 0; ++j);
        ans = max(ans, sum[i] * 2 - sum[j] + asum[j + 1]);
    }

    cout << ans << endl;

	return 0;
}
