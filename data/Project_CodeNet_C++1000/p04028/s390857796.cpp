#include <climits>
#include <iostream>

#define rep(i,i0,n) for (int (i) = (i0); (i) < (n); ++(i))

using namespace std;
using ll = long long;

const int M = 1e9 + 7;

const int I_MAX = 5001;
const int J_MAX = 5002;

int dp[I_MAX * J_MAX];


int solve(int n, string s) {

    ll m;
    int o_i, o_n;
    int dp_i0, dp_ij;
    ll ans;
    int r;

    fill(dp, dp + sizeof(dp) / sizeof(dp[0]), 0);
    dp[0] = 1;
    rep (i, 0, n) {
        o_i = J_MAX * i;
        dp_i0 = dp[o_i];
        o_n = o_i + J_MAX;
        dp[o_n] = dp_i0;
        dp[o_n + 1] = dp_i0 * 2 % M;
        rep (j, 1, n + 1) {
            dp_ij = dp[o_i + j];
            dp[o_n + j - 1] = (dp[o_n + j - 1] + dp_ij) % M;
            dp[o_n + j + 1] = (dp[o_n + j + 1] + dp_ij * 2) % M;
        }
    }

    m = s.length();
    ans = dp[J_MAX * n + m];
    r = 5e8 + 4;
    rep (i, 0, m) {
        ans *= r;
        ans %= M;
    }

    return (int)ans;
}


int main(int argc, const char * argv[]) {
    int n;
    string s;

    cin >> n;
    cin >> s;

    cout << solve(n, s) << endl;

    return 0;
}
