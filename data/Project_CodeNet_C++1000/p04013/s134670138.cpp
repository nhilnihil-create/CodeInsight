#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll dp[55][2525];
ll x[55];


int main(){

    ll N, A;
    cin >> N >> A;
    dp[0][0] = 1;
    rep1(i, N){
        ll x;
        cin >> x;
        // cout << "#" << x << endl;
        rrep1(num, N)rrep(sum, 2525)if(sum - x >= 0){
            dp[num][sum] += dp[num - 1][sum - x];
            // if(dp[num][sum])cout << num << ", " << sum << " : " << dp[num][sum] << endl;
        }
    }
    ll ans = 0;
    rep1(num, N)rep(sum, 2525)if(A * num == sum)ans += dp[num][sum];
    cout << ans << endl;

    return 0;
}