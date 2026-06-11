#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

void WF(int n,vector<vector<LL>> &d) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
    int N,M;cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    vector<int> c(M);

    vector<vector<LL>> G(N,vector<LL>(N,1 << 30));

    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
        G[a[i]][b[i]] = c[i];
        G[b[i]][a[i]] = c[i];
    }

    WF(N,G);
    int ans = 0;
    rep(i,M){
        if(G[a[i]][b[i]] < c[i])ans++;
    }
    cout << ans << endl;
}
