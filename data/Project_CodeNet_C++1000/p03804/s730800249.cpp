#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
char a[100][100], b[50][50]; 
int main() {
  int n,m;
  cin >> n >> m;
  rep(i,n) rep(j,n) cin >> a[i][j];
  rep(i,m) rep(j,m) cin >> b[i][j];

  for (int i = 0; m+i <= n; i++)
  {
    for (int j = 0; m+j <= n; j++) //(i,j)からスタートして比較する
    {
      bool ok = true;
      rep(k,m) rep(l,m) {
        if (b[k][l] != a[k+i][l+j]) {ok = false; continue;}
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    
  }
  
  cout << "No" << endl;
  return 0;
  
  return 0;
}