#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll h, w, n; cin >> h >> w >> n;
    vector<vector<ll>> color(h, vector<ll>(w, 0));

    // 0行目は右方向、端に着いたら1行目（下方向に1つ）
    // 1行目は左方向、端についたら2行目（下方向に2つ）・・・
    // と埋めていくのが効率が良い
    ll pos_i = 0, pos_j = 0;
    for(ll i=1; i<=n; i++){
        ll a; cin >> a;
        // 着色とカーソル移動
        while(a>0){
            a--;
            color[pos_i][pos_j] = i;
            (pos_i%2 == 0) ? pos_j++ : pos_j--;
            if(pos_j < 0 || pos_j >= w){
                pos_j = (pos_i%2 == 0) ? w-1 : 0;
                pos_i++;
            }
        }
    }

    // 出力処理
    for(ll i=0; i<h; i++){
        for(ll j=0; j<w; j++){
            cout << color[i][j] << ((j==w-1) ? endl : " ");
        }
    }
}