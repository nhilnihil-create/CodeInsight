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

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

int main(){
    int N, M; cin >> N >> M;
    vector<ll> x(N), y(M);
    for(int i=0; i<N; ++i) cin >> x[i];
    for(int i=0; i<M; ++i) cin >> y[i];

    ll X = 0, Y = 0;
    for(int i=0; i<N; ++i){
        X += i*x[i] - (N-1-i)*x[i];
        chmod(X);
    }

    for(int i=0; i<M; ++i){
        Y += i*y[i] - (M-1-i)*y[i];
        chmod(Y);
    }

    cout << X*Y%mod << endl;

    return 0;
}
