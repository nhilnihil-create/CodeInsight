#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// https://chakku.hatenablog.com/entry/2017/06/13/021049
// dp[i]][j]
// i個使用して重さの総和がj + w_0 iとなる時の最大値
ll dp[128][512];
int main() {
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> weight(N);
    vector<ll> value(N);
    REP(i, N) { cin >> weight[i] >> value[i]; }
    // weight value
    ll sum = 0;
    REP(i, N) {
        ll ww = weight[i] - weight[0];
        //荷物iを複数回使わないように逆に回す
        for(int j = i; j >= 0; j--) {
            for(int k = sum; k >= 0; k--) {
                //荷物iを含まないでj個
                //荷物iを含まない重さがk
                dp[j + 1][k + ww] = max(dp[j + 1][k + ww], dp[j][k] + value[i]);
            }
        }
        sum += ww;
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= sum; j++) {
            if(weight[0] * i + j > W) {
                continue;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}