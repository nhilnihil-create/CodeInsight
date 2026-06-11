#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

signed main()
{
   int n, m; cin >> n >> m;
   V<V<int>> G(n);
   for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--; b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   int q; cin >> q;
   V<int> vs(q), ds(q), cs(q);
   for (int i = 0; i < q; i++) {
      cin >> vs[i] >> ds[i] >> cs[i];
      vs[i]--;
   }

   int maxd = *max_element(ds.begin(), ds.end());
   V<V<int>> dp(n, V<int>(maxd+1, -1));
   for (int i = 0; i < q; i++) {
      dp[vs[i]][ds[i]] = i;
   }
   for (int d = maxd; d > 0; d--) {
      for (int v = 0; v < n; v++) {
         for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            chmax(dp[u][d-1], dp[v][d]);
         }
         chmax(dp[v][d-1], dp[v][d]);
      }
   }
   for (int v = 0; v < n; v++) {
      cout << (dp[v][0] == -1 ? 0 : cs[dp[v][0]]) << endl;
   }

   return 0;
}
