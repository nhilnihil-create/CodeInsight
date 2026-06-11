#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

const int mod = 1e9 + 7;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
    }
    return res;
}

void solve() {
    int N;
    cin >> N;
    string S; cin >> S;
    int L = S.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j + 1 <= N) {
                dp[i + 1][j + 1] += 2 * dp[i][j];
                dp[i + 1][j + 1] %= mod;
            } 
            dp[i + 1][max(0, j - 1)] += dp[i][j];
            dp[i + 1][max(0, j - 1)] %= mod;
        }
    }
    cout << (dp[N][L] * mod_pow(mod_pow(2, L, mod), mod - 2, mod)) % mod << endl;


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}