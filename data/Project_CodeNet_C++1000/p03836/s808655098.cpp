#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int main(){

    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    string ans = "";

    rep(i,ty-sy){
        ans += 'U';
    }
    rep(i,tx-sx){
        ans += 'R';
    }
    rep(i,ty-sy){
        ans += 'D';
    }
    rep(i,tx-sx){
        ans += 'L';
    }

    ans += 'L';
    rep(i,ty-sy+1){
        ans += 'U';
    }
    rep(i,tx-sx+1){
        ans += 'R';
    }
    ans += 'D';

    ans += 'R';
    rep(i, ty-sy+1){
        ans += 'D';
    }
    rep(i, tx-sx+1){
        ans += 'L';
    }
    ans += 'U';

    cout << ans << endl;

}