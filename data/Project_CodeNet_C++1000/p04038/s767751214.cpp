#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 1000000007;
vector<ll> inv, FactorialInv, Factorial;
ll beki(ll a, ll b){
    ll ret = 1 % mod;
    a %= mod;
    while(b) {
        if(b & 1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void init_combination(ll MAX){
    Factorial.resize(MAX + 1);
    FactorialInv.resize(MAX + 1);
    inv.resize(MAX + 1);
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

ll dp[3000][3000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination(5000000);
    ll N, K;
    cin >> N >> K;
    if(K == 1) {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] += combination(i-1+(K-1)*(j-1)+K-2, K-2) * (dp[i][j-1]);
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
        }
        for(int j = 0; j < i; j++) dp[i][j] = 0;
        for(int j = 1; j <= N; j++) {
            //cerr << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    ll ans = dp[N][N] * Factorial[N] % mod;
    cout << ans << endl;
    return 0;
}