#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  int l = -1, r = n;
  vector<vector<bool>> v(n+1,vector<bool>(k,false));
  while(r - l > 1) {
    int m = (l + r) / 2;
    bool can = false;
    rep(i,n+1) rep(j,k) v[i][j] = false;
    v[0][0] = true;
    rep(i,n) {
      rep(j,k) {
        if(v[i][j]) {
          v[i+1][j] = true;
          if(i != m && j + a[i] < k) v[i+1][j+a[i]] = true;
        }
      }
    }
    for(int i = max(0,k-a[m]); i < k; i++) {
      if(v[n][i]) can = true;
    }
    if(can) r = m;
    else l = m;
  }
  cout << l + 1 << endl;
  return 0;
}