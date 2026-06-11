#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;
using Graph = vector<vector<int>>;

signed _main(){
  // 頂点数と辺数
  int N, M; cin >> N >> M;

  // グラフ入力受取 (ここでは無向グラフを想定)
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,N){
    if(SZ(G[i])%2==1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
