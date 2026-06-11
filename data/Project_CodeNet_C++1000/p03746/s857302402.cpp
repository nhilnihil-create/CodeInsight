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

int dfs(const V<V<int>>& G, V<bool>& used, V<int>& prev, int v) {
   used[v] = true;
   int to = -1;
   for (int i = 0; i < G[v].size() && to == -1; i++) {
      int u = G[v][i];
      if (used[u]) continue;
      prev[u] = v;
      to = dfs(G, used, prev, u);
   }
   return (to == -1 ? v : to);
}

signed main()
{
   int n, m; cin >> n >> m;
   V<V<int>> G(n);
   for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--; b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   V<bool> used(n, false);
   V<int> prev(n, -1);
   V<int> ans;
   if (G[0].size() == 1) {
      int s = dfs(G, used, prev, 0);
      for (int v = s; v != -1; v = prev[v]) {
         ans.push_back(v);
      }
   } else {
      int s = dfs(G, used, prev, 0);
      int t = dfs(G, used, prev, 0);
      for (int v = s; v != -1; v = prev[v]) {
         ans.push_back(v);
      }
      V<int> tmp;
      for (int v = t; v != 0; v = prev[v]) {
         tmp.push_back(v);
      }
      for (int i = tmp.size()-1; i >= 0; i--) {
         ans.push_back(tmp[i]);
      }
   }

   cout << ans.size() << endl;
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << " ";
   }
   cout << endl;

   return 0;
}
