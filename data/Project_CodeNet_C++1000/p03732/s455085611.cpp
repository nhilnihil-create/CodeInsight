#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n, W; cin >> n >> W;
    vector<vector<ll>> values(4); //w, w+1, w+2, w+3;
    ll weight;
    rep(i, n){
        ll w, v; cin >> w >> v;
        if(i==0){
            weight = w;
            values[0].push_back(v); 
        }else{
            int index = w - weight;
            values[index].push_back(v);
        }
    }
    rep(i, 4) sort(all(values[i]), greater<ll>());

    vector<vector<ll>> S(4);
    rep(i, 4){
        S[i].push_back(0);
        rep(j, values[i].size()){
            S[i].push_back(S[i][j] + values[i][j]);
        }
    }

    ll res = 0;
    rep(a, S[0].size()){
        rep(b, S[1].size()){
            rep(c, S[2].size()){
                rep(d, S[3].size()){
                    ll sum_v = S[0][a] + S[1][b] + S[2][c] + S[3][d]; 
                    ll sum_w = a*weight + b*(weight+1) + c*(weight+2) + d*(weight+3);
                    if(sum_w <=W)chmax(res, sum_v);
                }
            }
        }
    }
    cout << res << ln;
}
