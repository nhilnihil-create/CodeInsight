#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long modpow(int n, int r) {
    long long ret = 1; long long tmp = (long long) n;
    while (r != 0) {
        if (r % 2) ret *= tmp;
        tmp *= tmp; tmp %= mod; ret %= mod;
        r /= 2;
    }
    return ret;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int l = s.size();
    vector<long long> dp(2*n+1, 0), dp2;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp2.assign(2*n+1, 0);
        for (int j = 0; j <= 2*n; j++) {
            if (j == 0) dp2[j] = (dp[j] + dp[j+1]) % mod;
            else dp2[j] = (dp[j-1]*2 + dp[j+1]) % mod;
        }
        swap(dp, dp2);
    }
    long long inv = modpow(2, mod-2);
    long long mul = modpow(inv, l);
    cout << dp[l] * mul % mod << endl;
    return 0;
}