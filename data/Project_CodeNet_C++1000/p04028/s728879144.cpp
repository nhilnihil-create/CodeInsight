#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

ll dp[5001][5001];

ll modpow(ll a, ll t) {
    ll ret = 1LL;
    while(t){
        if(t & 1LL){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        t >>= 1;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.length();

    dp[0][0] = 1;
    for(int i=0;i<n;++i) {
        for(int j=0;j<=i;++j) {
            dp[i+1][j+1] += (dp[i][j] * 2) % MOD;
            dp[i+1][j+1] %= MOD;
            dp[i+1][j?(j-1):0] += dp[i][j];
            dp[i+1][j?(j-1):0] %= MOD;
        }
    }

    ll patterns = modpow(2LL, m);
    ll ans = (dp[n][m] * modpow(patterns, MOD-2)) % MOD;

    cout << ans << endl;
}