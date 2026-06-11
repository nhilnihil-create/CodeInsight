#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> data(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> data.at(i).at(j);
    }
  }
  sort(data.begin(), data.end());
  vector<bool> b(n);
  vector<bool> c(n);
  for (int i = 0; i < m; i++) {
      if(data[i][0]==1)
      b[data[i][1]]=true;
      else if(data[i][1]==n)
      c[data[i][0]]=true;
    }
    for (int i = 0; i < n; i++){
      if(b[i] && c[i]){
      cout << "POSSIBLE" << endl;
      return 0;
      }
    } 
    cout << "IMPOSSIBLE" << endl;
}