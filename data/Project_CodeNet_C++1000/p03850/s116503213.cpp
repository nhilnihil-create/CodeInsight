#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 100;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

ll t[4 * maxn];
ll to_add[4 * maxn];
void push(int v) {
    if (to_add[v]) {
        t[v << 1] += to_add[v];
        t[v << 1 | 1] += to_add[v];
        to_add[v << 1] += to_add[v];
        to_add[v << 1 | 1] += to_add[v];
        to_add[v] = 0;
    }
}
void add(int v, int tl, int tr, int l, int r, int val) {
    if (tl >= r || l >= tr) {
        return;
    }
    if (tl >= l && tr <= r) {
        to_add[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    add(v << 1, tl, tm, l, r, val);
    add(v << 1 | 1, tm, tr, l, r, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}
ll get(int v, int tl, int tr, int l, int r) {
    if (l >= tr || tl >= r) {
        return -INF;
    }
    if (tl >= l && tr <= r) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm, tr, l, r));
}
int main() {
    int n;
    cin >> n;

    vector<int> vals;
    vector<char> symbols;
    symbols.push_back('+');
    for (int i = 0; i + 1 < n; ++i) {
        int x;
        cin >> x;
        vals.emplace_back(x);
        char c;
        cin >> c;
        symbols.emplace_back(c);
    }
    int x;
    cin >> x;
    vals.push_back(x);
    if (n == 1) {
        cout << vals.back();
        return 0;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(3));
    for (auto &vec:dp) {
        for (auto &el:vec) {
            el = -INF;
        }
    }
    dp[0][0] = 0;
    auto get_sign = [](int pw) {
        return pw & 1 ? -1 : 1;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            if (dp[i][j] == -INF) {
                continue;
            }
//            cout << i << " " << j << " " << dp[i][j] << endl;
            if (symbols[i] == '-') {
                if (j == 0) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + get_sign(j + 1) * vals[i]);
                } else {
                    for (int e = 1; e <= 2; ++e) {
                        dp[i + 1][e] = max(dp[i + 1][e], dp[i][j] + get_sign(e) * vals[i]);
                    }
                }
            } else {
                for (int e = 0; e <= j; ++e) {
                    dp[i + 1][e] = max(dp[i + 1][e], dp[i][j] + get_sign(e) * vals[i]);
                }
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}
