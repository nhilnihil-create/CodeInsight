#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N, W; cin >> N >> W;
    vector<ll> w0, w1, w2, w3;
    ll wo, vo;
    cin >> wo >> vo;
    w0.push_back(vo);

    for(int i=0; i<N-1; ++i){
        ll w, v; cin >> w >> v;
        if(w == wo) w0.push_back(v);
        else if(w == wo+1) w1.push_back(v);
        else if(w == wo+2) w2.push_back(v);
        else w3.push_back(v); 
    }

    sort(w0.begin(), w0.end(), greater<ll>());
    sort(w1.begin(), w1.end(), greater<ll>());
    sort(w2.begin(), w2.end(), greater<ll>());
    sort(w3.begin(), w3.end(), greater<ll>());

    ll ans = 0;
    for(int i=0; i<=w0.size(); ++i){
        for(int j=0; j<=w1.size(); ++j){
            for(int k=0; k<=w2.size(); ++k){
                for(int l=0; l<=w3.size(); ++l){
                    ll tw = 0, tv = 0;
                    tw = wo*i + (wo+1)*j + (wo+2)*k + (wo+3)*l;
                    if(tw > W) continue;
                    for(int a=0; a<i; ++a) tv += w0[a];
                    for(int a=0; a<j; ++a) tv += w1[a];
                    for(int a=0; a<k; ++a) tv += w2[a];
                    for(int a=0; a<l; ++a) tv += w3[a];
                    ans = max(ans, tv);
                }
            }
        }
    }

    cout << ans << endl;
}