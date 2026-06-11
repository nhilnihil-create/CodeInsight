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

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

int main(){
    ll N, X;
    cin >> N >> X;

    ll res = N;
    ll a = max(X, N-X);
    ll b = min(X, N-X);

    while(b){
        ll q = a/b;
        ll r = a%b;

        res += 2*q*b;

        if(r == 0) res -= b;

        a = b;
        b = r;
    }

    cout << res << endl;
    return 0;
}