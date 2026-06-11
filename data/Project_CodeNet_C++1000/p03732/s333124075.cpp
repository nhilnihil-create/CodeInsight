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
// https://emtubasa.hateblo.jp/entry/2018/11/24/000000
// dp[i]][j][k]
// i番目までの荷物の中でj個利用した時に総重量がkとなるような組み合わせの中で最大の値
ll dp[128][128][305];
// https://atcoder.jp/contests/abc060/submissions/3639903
int main() {
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> weight(N);
    vector<ll> value(N);
    REP(i, N) { cin >> weight[i] >> value[i]; }
    // weight value
    ll ans = 0;
    ll fin = W / weight[0];
    ll finw = W % weight[0];
    ll fw = weight[0];
    for(int i = 0; i < N; i++) {
        weight[i] -= fw;
    }
    dp[0][1][0] = value[0];
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i + 1; j++) {
            for(int k = 0; k <= 300; k++) {
                if(i == 0) {
                    continue;
                }
                dp[i][j][k] = dp[i - 1][j][k];
                if(k - weight[i] >= 0) {
                    dp[i][j][k] =
                        max(dp[i][j][k],
                            dp[i - 1][j - 1][k - weight[i]] + value[i]);
                }
            }
        }
    }

    for(int i = 0; i <= N + 1; i++) {
        for(int j = 0; j <= 304; j++) {
            if(fw * i + j > W) {
                continue;
            }
            ans = max(ans, dp[N - 1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}