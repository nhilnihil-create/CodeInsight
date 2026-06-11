#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  bool ok = false;
  for(int nv: G.at(0)){
    for(int g: G.at(nv)){
      if(g == n-1) ok = true;
    }
  }
  if(ok) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}