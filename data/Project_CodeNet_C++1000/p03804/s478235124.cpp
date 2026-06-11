#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;


int main(){
  int n,m; cin >> n >> m;
  string a[n], b[m];
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  int cnt = 0;
  for(int i = 0; i <= n-m; i++){
    for(int j = 0; j <= n-m; j++){
      bool flg = true;
      for(int bi = 0; bi < m; bi++){
        for(int bj = 0; bj < m; bj++){
          if(b[bi][bj] != a[i+bi][j+bj]) flg = false;
        }
      }
      if(flg) cnt++;
    }
  }
  if(cnt) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
