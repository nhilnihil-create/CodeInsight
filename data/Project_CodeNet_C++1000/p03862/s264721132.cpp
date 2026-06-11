#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, x;
    cin >> n >> x;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint res = 0;

    for (int i = 1; i < n; i++) {
        int tot = a[i] + a[i-1];
        tot -= x;
        if (tot <= 0) continue;
        res += tot;
        if (tot > a[i]) {
            tot -= a[i];
            a[i] = 0;
        }
        else {
            a[i] -= tot;
        }
    }

    cout << res << endl;
    return 0;
}