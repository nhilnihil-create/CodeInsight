#include <bits/stdc++.h>
#define Task        "test"
#define pb          emplace_back
#define fi          first
#define se          second
#define mp          make_pair
#define ll          long long
//#define int         int64_t

using namespace std;

typedef pair<ll, ll> pii;
const int N = (int)2e5 + 2;
const ll inf = (ll)1e18;

ll f[N][3];
int n, a[N];
char op[N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; op[0] = '+';
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(i < n) cin >> op[i];
    }
    fill_n(&f[0][0], N * 3, -inf);
    f[1][0] = a[1];
    for(int i = 2; i <= n; ++i) {
        if(op[i - 1] == '-') a[i] *= (-1);
        f[i][0] = max(max(f[i - 1][0], f[i - 1][2]) + a[i], f[i - 1][1] - a[i]);
        f[i][1] = max(f[i - 1][1] - a[i], f[i - 1][2] + a[i]);
        f[i][2] = f[i - 1][2] + a[i];
        if(op[i - 1] == '-') {
            f[i][1] = max(f[i - 1][0] + a[i], f[i][1]);
            f[i][2] = max(f[i - 1][1] - a[i], f[i][2]);
        }
    }
    cout << f[n][0];
}
