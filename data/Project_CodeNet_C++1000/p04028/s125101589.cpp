#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = (int)5e3 + 5,
          mod = (int)1e9 + 7;
int n, dp[N][N];
string s;

int add(int _a, int _b) {
    _a += _b;
    if (_a >= mod) _a -= mod;
    return _a;
}

int mul(int _a, int _b) { return (int)( (ll)_a * _b % mod); }

int binPow (int _a, int _m) {
    int ret = 1;
    for (; _m; _m >>= 1, _a = mul(_a, _a) ) if (_m & 1) ret = mul(ret, _a);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s;

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) if (dp[i][j]) {
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(2, dp[i][j]) );
            dp[i + 1][ max(0, j - 1) ] = add(dp[i + 1][ max(0, j - 1) ], dp[i][j]);
        }
    }

    cout << mul(dp[n][(int)s.size()], binPow(binPow(2, (int)s.size() ), mod - 2) );

    return 0;
}
