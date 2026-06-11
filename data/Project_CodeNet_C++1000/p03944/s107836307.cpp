#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int x[n], y[n], a[n];
  rep(i, n) cin >> x[i] >> y[i] >> a[i];
  
  vector<vector<bool>> s(h, vector<bool>(w));
  rep(i, n){
    if(a[i] == 1){
      rep(j, x[i]){
        rep(k, h) s[k][j] = true;
      }
    }
    if(a[i] == 2){
      for(int j = x[i]; j < w; j++){
        rep(k, h) s[k][j] = true;
      }
    }
    if(a[i] == 3){
      rep(j, y[i]){
        rep(k, w) s[j][k] = true;
      }
    }
    if(a[i] == 4){
      for(int j = y[i]; j < h; j++){
        rep(k, w) s[j][k] = true;
      }
    }
  }
  int cnt = 0;
  rep(i, h){
    rep(j, w){
      if(!s[i][j]) cnt++;
    }
  }
  cout << cnt << endl;
}
