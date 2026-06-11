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

const ll inf = 1LL<<59;

int N;
vector<vector<ll>> d(334, vector<ll>(334, inf));

void floyd(){
    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            if(d[i][k] == inf) continue;
            for(int j=0; j<N; ++j){
                if(d[j][k] == inf) continue;

                chmin(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    cin >> N;
    ll a[334][334];
    ll ans = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> a[i][j];
            d[i][j] = a[i][j];
            ans += a[i][j];
        }
    }
    ans /= 2;

    floyd();
    bool flg = true;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(a[i][j] != d[i][j]) flg = false;
        }
    }
    if(!flg){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            for(int w=0; w<N; w++){
                if(w == i || w == j) continue;

                if(d[i][j] == d[i][w]+d[j][w]){
                    ans -= a[i][j];
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    
}
