#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m;
ll fac[N];

int main() {
    cin >> n >> m;
    fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    if (abs(n - m) > 1) {
        cout << 0 << endl;
    } else {
        ll ans = fac[m] * fac[n] % mod;
        if (n == m)
            ans = ans * 2 % mod;
        cout << ans << endl;
    }
    return 0;
}
