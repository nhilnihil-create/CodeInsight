#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;


int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);

  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bool flag = 0;
  for(auto v : g[0]){
    for(auto to : g[v]){
      if(to == n-1) flag = 1;
    }
  }
  if(flag) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
