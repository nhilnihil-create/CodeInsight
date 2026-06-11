#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N, K; cin >> N >> K;
    vector<ll> a(N+1, 0);
    for(int i=1; i<=N; ++i) cin >> a[i];

    ll ans = 0;
    vector<ll> cum(N+1, 0), poscum(N+1, 0);
    for(int i=1; i<=N; ++i){
        cum[i] = cum[i-1] + a[i];
        if(a[i] > 0) poscum[i] = poscum[i-1] + a[i];
        else poscum[i] = poscum[i-1];
    }

    for(int left=1; left<=N+1-K; ++left){
        ll tmp = max(0LL, cum[left+K-1] - cum[left-1]);
        tmp += poscum[left-1] + (poscum[N]-poscum[left+K-1]);
        chmax(ans, tmp);
    }

    cout << ans << endl;
}