#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int MAXN = 123456;
int bg[2 * MAXN], ed[2 * MAXN], a[MAXN];
LL red[2 * MAXN], offs[2 * MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    LL cost = 0;
    for (int i = 1; i < n; i++) {
        int pre = a[i - 1], cur = a[i];
        if (cur < pre) cur += m;
        cost += (cur - pre);
        bg[pre]++, ed[cur]++;
        offs[cur] += (cur - pre);
    }
    LL cnt = 0, sum = 0;
    for (int i = 1; i <= 2 * m; i++) {
        red[i] = sum - cnt;
        cnt = cnt - ed[i] + bg[i];
        sum += cnt - offs[i];
    }
    LL ans = cost;
    for (int i = 1; i <= m; i++) {
        LL tmp = red[i] + red[i + m];
        ans = min(ans, cost - tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
