#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  int INF = INT_MAX;
  ll mod = 1e9+7;
  // lld PI = 3.141592653;



  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     // fstream cin("text.txt");

      int n;
      cin>>n;
      vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>(0));
      int m;
      cin>>m;
      set<pair<int,int>> edges;
      for (int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        edges.insert({a,b});
      }
      for (int now = 1; now<=n; now++){
      vector<int> d(n+1, INF);
      vector<bool> visited(n+1);
      vector<int> p(n+1);
      // int now = 1;
      d[now] = 0;
      for (int i = 0; i<n; i++){
        int mini = 1;
        for (int j =2; j<=n; j++){
          if (!visited[j] && (visited[mini] || d[j] < d[mini])) mini = j;
        }
        // cout<<mini<endl;
        // if (d[mini] == INF) break;
        visited[mini] = true;
        // cout<<mini<<endl;
        for (pair<int,int> a: adj[mini]){
          if (d[mini] + a.second < d[a.first]){
            d[a.first] = d[mini] + a.second;
            p[a.first] = mini;
          }
          // d[a.first] = min(d[a.first], d[now]+a.second);
        }

      }
      
      for (int t = 1; t<=n; t++){
        vector<int> path;
        for (int v = t; v!= now; v = p[v]) path.push_back(v);
        path.push_back(now);
        for (int i = 1; i< path.size();i++) {

          edges.erase({path[i], path[i-1]});
          edges.erase({path[i-1], path[i]});
        }
      }

    }
    cout<<edges.size()<<"\n";
      // for (int i = 1; i<=n; i++) cout<<d[i]<<" ";
      //   cout<<endl;
      //   for (int i = 1; i<=n; i++) cout<<p[i]<<" ";
      // cout<<endl;

}
  