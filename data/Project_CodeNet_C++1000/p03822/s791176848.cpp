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

void topological_sort(const vector<vector<int>>& G, vector<int>& ord)
{
   vector<int> num(G.size(),0);
   for (int i = 0; i < G.size(); i++) {
      for (int j = 0; j < G[i].size(); j++) {
         num[G[i][j]]++;
      }
   }
   stack<int> st;
   for(int i = 0; i < num.size(); i++) {
      if (num[i] == 0) {
         st.push(i);
      }
   }
   for (int k = 0; !st.empty(); k++) {
      int i = st.top(); st.pop();
      ord[k] = i;
      for(int j = 0; j < G[i].size(); j++) {
         num[G[i][j]]--;
         if (num[G[i][j]] == 0) {
            st.push(G[i][j]);
         }
      }
   }
}

signed main()
{
   int n; cin >> n;
   V<V<int>> G(n);
   for (int i = 1; i < n; i++) {
      int v; cin >> v; v--;
      G[v].push_back(i);
   }
   DUMP(G)

   V<int> ord(n);
   topological_sort(G, ord);
   DUMP(ord)

   V<int> dp(n);
   for (int k = n-1; k >= 0; k--) {
      int v = ord[k];
      if (G[v].size() == 0) continue;

      int m = G[v].size();
      V<int> tmp(m);
      for (int i = 0; i < m; i++) {
         tmp[i] = dp[G[v][i]];
      }
      sort(tmp.begin(), tmp.end());
      for (int i = 0; i < m; i++) {
         tmp[i] += m - i;
      }
      sort(tmp.begin(), tmp.end());

      dp[v] = tmp[m-1];
   }
   DUMP(dp)

   cout << dp[0] << endl;

   return 0;
}
