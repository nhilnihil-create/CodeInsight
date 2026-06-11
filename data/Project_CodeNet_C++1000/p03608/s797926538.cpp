#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MAX_V = 300;
// d[u][v]は辺（u, v)のコスト
vector<vector<ll> > d(MAX_V, vector<ll>(MAX_V, INF));
// 頂点数
ll V;

int perm[8];
ll MIN = INF;

void permutation(int n) {
    do {
        ll res = 0;
        // permに対する操作
        rep(i, n-1){
            res += d[perm[i]][perm[i+1]];
        }
        chmin(MIN, res);
    } while (next_permutation(perm, perm + n));
    return;
    
}

void warshall_floyd() {
    rep(k, V){
        rep(i, V){
            rep(j, V){
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// ---------------------------------------------------
// O(|V|^3) すべての２頂点間の最短路を求める(ワーシャル・フロイド法)
// ---------------------------------------------------

int main(){
    ll E, a, b, cost, R;
    cin >> V >> E >> R;
    rep(i, R){
        cin >> a;
        a--;
        perm[i] = a;
    }
    sort(perm, perm+R);

    // 対角線は0に設定(それ以外はINF)
    rep(i, V){
        d[i][i] = 0;
    }
    rep(i, E){
        cin >> a >> b >> cost;
        a--; b--; //0-index
        d[a][b] = cost;
        d[b][a] = cost;
    }
    // 実行
    warshall_floyd();

    permutation(R);
    cout << MIN << endl;
}