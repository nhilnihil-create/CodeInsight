

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  char c[n][n];
  char d[m][m];
  rep(i, n){
    rep(j, n) cin >> c[i][j];
  }
  rep(i, m){
    rep(j, m) cin >> d[i][j];
  }
  string ans = "No";
  int cnt = 0;
  for(int i = 0; i <= n - m; i++) {
    for(int j = 0; j <= n - m; j++) {
      for(int k = 0; k < m; k++) {
        for(int l = 0; l < m; l++) {
          if(c[i + k][j + l] == d[k][l]) cnt++;
        }
      }
      if(cnt == m * m) ans = "Yes";
      cnt = 0;
    }
  }
    
  cout << ans << endl;

  return 0;
}