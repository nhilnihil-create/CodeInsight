#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    ll N, W; cin >> N >> W;
    vector<ll> w0, w1, w2, w3;
    ll sample; cin >> sample;
    ll v; cin >> v;
    w0.push_back(v);

    for(int i=0; i<N-1; i++){
        ll w, v; cin >> w >> v;
        if(w == sample) w0.push_back(v);
        else if(w == sample+1) w1.push_back(v);
        else if(w == sample+2) w2.push_back(v);
        else w3.push_back(v);
    }

    sort(w0.begin(), w0.end(), greater<ll>());
    sort(w1.begin(), w1.end(), greater<ll>());
    sort(w2.begin(), w2.end(), greater<ll>());
    sort(w3.begin(), w3.end(), greater<ll>());

    ll ans = 0;
    for(int i=0; i<=w0.size(); i++){
        for(int j=0; j<=w1.size(); j++){
            for(int k=0; k<=w2.size(); k++){
                for(int l=0; l<=w3.size(); l++){

                    if(i*sample + j*(sample+1) + k*(sample+2) + l*(sample+3) <= W){
                        ll tmp = 0;
                        for(int a=0; a<i; a++) tmp += w0[a];
                        for(int a=0; a<j; a++) tmp += w1[a];
                        for(int a=0; a<k; a++) tmp += w2[a];
                        for(int a=0; a<l; a++) tmp += w3[a];

                        ans = max(ans, tmp);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}