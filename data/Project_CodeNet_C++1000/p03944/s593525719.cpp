#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll w, h, n;
  cin >> w >> h >> n;
  
  vector<vector<ll>> t(h, vector<ll>(w, 0));

  for (int i = 0; i < n; i++){
    ll x, y, a;
    cin >> x >> y >> a;
    
    if (a == 1){
      for (int i = 0; i < h; i++){
        for (int j = 0; j < x; j++){
          t[i][j] = 1;
        }
      }
    }
    else if (a == 2){
      for (int i = 0; i < h; i++){
        for (int j = x; j < w; j++){
          t[i][j] = 1;
        }
      }
    }
    else if (a == 3){
      for (int i = 0; i < y; i++){
        for (int j = 0; j < w; j++){
          t[i][j] = 1;
        }
      }
    }
    else if (a == 4){
      for (int i = y; i < h; i++){
        for (int j = 0; j < w; j++){
          t[i][j] = 1;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      ans += 1 - t[i][j];
    }
  }
  cout << ans << endl;

  return 0;
}
