#include <iostream>
#include <map>
using namespace std;
#define ll long long

int main () {
  ll h, w, n;
  cin >> h >> w >> n;
  ll a[n], b[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i] >> b[i];  
    a[i]--;
    b[i]--;
  } 
   
  // m[i][j] i, jの位置が3 * 3の正方形の中心となる.
  map<ll, map<ll, ll> > m; 
  ll va[3] = {0, 1, -1};
  ll vb[3] = {0, 1, -1};
  for (ll i = 0; i < n; i++) {
    
    // 上からa[i], 左からb[i]について  
    for (ll p = 0; p < 3; p++) {
      for (ll q = 0; q < 3; q++) {
        ll y = a[i] + va[p];
        ll x = b[i] + vb[q];
        
        // 上からy，右からxについてそれを中心とする3 * 3の正方形ができるか考える
        if (y >= 1 && x >= 1 && y <= (h - 2) && x <= (w - 2)) {
          m[y][x]++;  
        }    
      }  
    }
  }
  ll sum[10];
  for (ll i = 0; i <= 9; i++) {
    sum[i] = 0;  
  }
  for (auto i : m) {
    for (auto j : i.second) {
      sum[j.second]++;
    }
  }
  ll res = 0;
  for (ll i = 1; i <= 9; i++) {
    res += sum[i];    
  }
  sum[0] = (h - 2) * (w - 2) - res;
  for (ll i = 0; i <= 9; i++) {
    cout << sum[i] << endl;  
  }
}