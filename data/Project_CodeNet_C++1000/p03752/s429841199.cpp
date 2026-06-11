#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll ans = INF;
    rep(bit, 1<<N) {
        ll cost = 0, color = 0, maxa = 0;
        rep(i, N) {
            if (a[i] > maxa) {
                color++;
                maxa = a[i];
            }
            else if (bit>>i&1) {
                color++;
                maxa++;
                cost += maxa - a[i];
            }
        }
        if(color >= K) chmin(ans, cost);
    }
    cout << ans << endl;
}
