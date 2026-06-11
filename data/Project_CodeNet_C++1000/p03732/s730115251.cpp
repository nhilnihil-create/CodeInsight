#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

const ll MAXN = 100 + 10;
ll w[MAXN], v[MAXN];
ll dp[MAXN][MAXN][3*MAXN+1];

int main() {
    FAST_IO();
    ll N, W; cin >> N >> W;
    repp(i, 1, N) cin >> w[i] >> v[i];
    for(ll i = 1; i <= N; ++i) {
        for(ll k = 1; k <= i; ++k) {
            for(ll x = 0; x <= 3*N; ++x) {
                if(i == 1) dp[i][k][x] = v[1];
                else {
                    if(x - w[i] + w[1] >= 0 && i == k) dp[i][k][x] = dp[i-1][k-1][x - w[i] + w[1]] + v[i];
                    else if(x - w[i] + w[1] >= 0 && i != k) dp[i][k][x] = max(dp[i-1][k][x], dp[i-1][k-1][x - w[i] + w[1]] + v[i]);
                    else dp[i][k][x] = dp[i-1][k][x];
                }
            } 
        }
    }
    
    ll ans = 0;
    for(int k = 1; k <= N; ++k) {
        if(W - k * w[1] < 0) continue;
        if(W - k * w[1] <= 3*k) ans = max(ans, dp[N][k][W - k*w[1]]);
        else ans = max(ans, dp[N][k][3*k]);
    }
    cout << ans << endl;
}