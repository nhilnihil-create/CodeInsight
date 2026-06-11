#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define rr int
using namespace std;
typedef long long ll;
ll read() {
    char i = getchar();
    ll f = 1, res = 0;
    while (i < '0' || i > '9') {
        if (i == '-') f = -1;
        i = getchar();
    }
    while (i >= '0' && i <= '9') {
        res = res * 10 + i - '0';
        i = getchar();
    }
    return f * res;
}
int n;
ll K;
const int N = 3e5 + 50;
ll a[N];
ll sum[N], c[N];
ll ans = 0;
inline void merge(int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        merge(l, mid);
        merge(mid + 1, r);
        int i = l, j = mid + 1, now = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                c[now++] = a[i++];
                ans += r - j + 1; //这里注意不能重复计算，每次取得取单独更新贡献
            } else
                c[now++] = a[j++];
        }
        while (i <= mid) c[now++] = a[i++];
        while (j <= r) c[now++] = a[j++];
        for (rr i = l; i <= r; ++i) a[i] = c[i];
    }
}
int main() {
    n = read() + 1, K = read();
    for (rr i = 2; i <= n; ++i) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
        a[i] = sum[i] - K * ll(i - 1);
    }
    // for (rr i = 1; i <= n; ++i) cout << a[i] << ' ';
    merge(1, n);
    // for (rr i = 1; i <= n; ++i) cout << a[i] << endl;
    cout << ans;
}