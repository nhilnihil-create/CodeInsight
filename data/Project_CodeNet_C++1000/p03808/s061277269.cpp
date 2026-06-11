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
    ll N; cin >> N;
    ll sum = 0;

    vector<ll> a(N),d(N);
    for(int i=0; i<N; ++i) { cin >> a[i]; sum += a[i]; }

    if(sum%(N*(N+1)/2) != 0){
        cout << "NO" << endl;
        return 0;
    }

    ll k = sum/(N*(N+1)/2);
    for(int i=0; i<N; ++i) d[i] = a[(i+1)%N] - a[i];
    for(int i=0; i<N; ++i) d[i] -= k;

    ll cnt = 0;
    for(int i=0; i<N; ++i){
        // d[i] > 0で弾くのを忘れずに
        if(d[i] > 0){
            cout << "NO" << endl;
            return 0;
        }
        else if((-d[i])%N != 0){
            cout << "NO" << endl;
            return 0;
        }
        else{
            cnt += (-d[i])/N;
        }
    }   

    if(cnt == k){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}