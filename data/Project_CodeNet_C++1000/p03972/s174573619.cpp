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
    const ll inf = 1LL<<59;
    ll W, H; cin >> W >> H;
    vector<ll> p(W+1), q(H+1);
    for(int i=0; i<W; ++i) cin >> p[i];
    for(int i=0; i<H; ++i) cin >> q[i];
    p[W] = q[H] = inf;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());


    ll ans = 0;
    ll row = H+1, cul = W+1;

    int i = 0, j = 0;
    for(int loop=0; loop<H+W; ++loop){
        //printf("p[i]: %lld, q[j]: %lld\n", p[i], q[j]);
        if(p[i] <= q[j]){
            ans += p[i]*row;
            ++i;
            --cul;
        }
        else{
            ans += q[j]*cul;
            ++j;
            --row;
        }
    }

    cout << ans << endl;
}