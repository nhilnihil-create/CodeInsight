#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define RFOR(i, l, r) for (int i = (int)(r); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vi x(n);
    REP(i, n) {int a; cin >> x[i];}
    int l, q;
    cin >> l >> q;

    vvi dp(30, vi(100005, 0));
    REP(i, n) {
        auto it = upper_bound(all(x), x[i] + l);
        it--;
        dp[0][i] = it - x.begin();
        // cout << dp[0][i] << " ";
    }
    // int low = 1, high = 30;cout << endl;

    FOR(i, 1, 30) {
        // cout << " day " << i << " : ";
        REP(j, n) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        //    cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    REP(i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        int ans = 0;
        RREP(i, 30) {
            if (dp[i][a] < b) {
                a = dp[i][a];
                ans += 1 << i;
            }
        }

        cout << ans + 1 << endl;
    }



    return 0;
}