
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
const num inf = 0x3f3f3f3f3f3f3f3f;
int n, a[nsz + 5];
num dp[nsz + 5][5], ans;
string dat[nsz + 5];

int inline to(string s) {
    int res = 0;
    loop (i, s.size()) {
        res *= 10;
        res += s[i] ^ 48;
    }
    return res;
}

void inline upd(num &a, num b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    dat[0] = '+';
    cont (i, 2 * n - 1) {
        cin >> dat[i];
        if (i & 1) {
            int cur = to(dat[i]);
            a[i >> 1] = dat[i - 1] == "-" ? -cur : cur;
        }
    }
    memset(dp, -inf, sizeof(dp));
    dp[0][0] = 0;
    loop (i, n) {
        loop (k, 3) {
            num val = dp[i][k], cur = k & 1 ? -a[i] : a[i];
            for (int l = k - 1; l >= 0; --l) {
                upd(dp[i + 1][l], val + cur);
            }
            if (k < 2 && a[i] < 0) {
                upd(dp[i + 1][k + 1], val + cur);
            }
            upd(dp[i + 1][k], val + cur);
        }
    }
    loop (k, 3) {
        upd(ans, dp[n][k]);
    }
    cout << ans << ln;
}