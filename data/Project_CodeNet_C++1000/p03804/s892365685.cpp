#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(n));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> v[i][j];
    }
  }
  
  vector<vector<char>> w(m, vector<char>(m));
  for(int i=0; i<m; i++) {
    for(int j=0; j<m; j++) {
      cin >> w[i][j];
    }
  }
  
  //25**4
  int count = 0;
  bool include = false;
  for(int i=0; i<=n-m; i++) {
    for(int j=0; j<=n-m; j++) {
      for(int k=0; k<m; k++) {
        for(int l=0; l<m; l++) {
          if(v[i+k][j+l] == w[k][l]) count++;
        }
        if(count == m*m) include = true;
      }
      if(include) goto SKIP;
      count = 0;
    }
  }
  SKIP:
  if(include) cout << "Yes" << endl;
  else cout << "No" << endl;
}