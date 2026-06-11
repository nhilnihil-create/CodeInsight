#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    int N, K; cin >> N >> K;
    vector<ll> a(N+1);
    for(int i=1; i<=N; i++) cin >> a[i];

    vector<ll> cum(N+1, 0);
    vector<ll> cum2(N+1, 0);
    for(int i=1; i<=N; i++) cum[i] = cum[i-1]+a[i];
    for(int i=1; i<=N; i++) cum2[i] = cum2[i-1]+max(0LL, a[i]);

    ll ans = -(1LL<<59);
    for(int i=1; i<=N+1-K; i++){
        ll tmp = cum[i+K-1]-cum[i-1];
        ll tmp2 = 0;
        tmp += cum2[i-1] + cum2[N]-cum2[i+K-1];
        tmp2 += cum2[i-1] + cum2[N]-cum2[i+K-1];

        ans = max(ans, max(tmp, tmp2));
    }

    cout << ans << endl;
}