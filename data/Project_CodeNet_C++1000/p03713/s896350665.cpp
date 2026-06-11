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


pair<ll, ll> divide(ll h, ll w){
    if (h % 2 == 0 || w % 2 == 0) return {h*w/2, h*w/2};
    if (h > w) swap(h,w);
    return {h*((w+1)/2), h*((w-1)/2)};
    
}

int main(){
    
    long long H, W;
    cin >> H >> W;

    ll ans = INF;
    // Wは固定で高さを全探索
    for (ll h = 1; h < H; h++){
        vector<ll> area(3);
        area[0] = h*W;
        pair<ll, ll> p = divide(H-h, W);
        area[1] = p.first;
        area[2] = p.second;
        sort(area.begin(), area.end());
        ans = min(ans, area[2]-area[0]);
    }

    // Hは固定で幅を全探索
    for (ll w = 1; w < W; w++){
        vector<ll> area(3);
        area[0] = H*w;
        pair<ll,ll> p = divide(H,W-w);
        area[1] = p.first;
        area[2] = p.second;
        sort(area.begin(), area.end());
        ans = min(ans, area[2]-area[0]);
    }

    cout << ans << endl;

}