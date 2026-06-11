#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ship(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    ship.at(a).push_back(b);
    ship.at(b).push_back(a);
  }
  
  bool ok = false;
  queue<int> dfs;
  dfs.push(0);
  for(int i = 0; i < 2; i++){
    queue<int> check;
    while(dfs.size() > 0){
      check.push(dfs.front());
      dfs.pop();
    }
    
    while(check.size() > 0){
      int now = check.front();
      check.pop();
      for(auto next : ship.at(now)) dfs.push(next);
    }
  }
  
  while(dfs.size() > 0){
    if(dfs.front() == n-1) ok = true;
    dfs.pop();
  }
  
  if(ok) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}