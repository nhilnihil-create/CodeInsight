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

V<int> As;
V<V<int>> G;
int dfs(int p, int v) {
   if (G[v].size() == 1) return As[v];
   V<int> rec;
   for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i];
      if (u == p) continue;
      int res = dfs(v, u);
      if (res == INF) {
         return INF;
      } else {
         rec.push_back(res);
      }
   }
   int B = 2 * As[v] - accumulate(rec.begin(), rec.end(), 0LL);
   if (B > As[v]) return INF;
   int over = 0;
   for (int i = 0; i < rec.size(); i++) {
      over += max(rec[i] - (As[v] - B), 0LL);
   }
   if (over > B) return INF;
   return B;
}

signed main()
{
   int n; cin >> n;
   As.resize(n);
   for (int i = 0; i < n; i++) {
      cin >> As[i];
   }
   G.resize(n);
   for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b; a--; b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   if (n == 2) {
      cout << (As[0] == As[1] ? "YES" : "NO") << endl;
      return 0;
   }

   int root = -1;
   for (int i = 0; i < n; i++) {
      if (G[i].size() > 1) {
         root = i; break;
      }
   }

   int res = dfs(-1, root);
   cout << (res == 0 ? "YES" : "NO") << endl;

   return 0;
}
