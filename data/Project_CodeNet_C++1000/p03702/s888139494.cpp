#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 123;

ll n, a, b;

ll h[N], c[N];

int main () {
    cin >> n >> a >> b;
    for (int i = 1;i <= n;i ++) {
        cin >> h[i];
        c[i] = h[i];
    }sort (h + 1, h + n + 1);
    sort (c + 1, c + n + 1);
    ll l = 1, r = 1e9, ans = 1;
    while (l <= r) {
        ll mid = (l + r) / 2, cnt = 0;
        for (int i = 1;i <= n;i ++) {
            c[i] -= mid * b;
        }
        for (int i = n;i >= 1;i --) {
            if (c[i] > 0) {
                ll val = c[i] / (a - b);
                if (c[i] % (a - b)) val ++;
                cnt += val;
            }
        }
        if (cnt <= mid) {
            r = mid - 1;
            ans = mid;
        }else {
            l = mid + 1;
        }
        for (int i = 1;i <= n;i ++) {
            c[i] = h[i];
        }
    }cout << ans;
}
