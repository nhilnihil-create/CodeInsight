#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  //残っている白い領域の左下の座標をbに　右上の座標をcに代入
  vector<int> b = {0,0}, c = {w,h};
  for (vector<int> d : a) {
    
    if (d.at(2) == 1) {
      if (d.at(0) > b.at(0)) {
        if (d.at(0) <= c.at(0)) b.at(0) = d.at(0);
        else b.at(0) = c.at(0);
      }
    }
    
    if (d.at(2) == 2) {
      if (d.at(0) < c.at(0)) {
        if (d.at(0) >= b.at(0)) c.at(0) = d.at(0);
        else c.at(0) = b.at(0);
      }
    }
    
    if (d.at(2) == 3) {
      if (d.at(1) > b.at(1)) {
        if (d.at(1) <= c.at(1)) b.at(1) = d.at(1);
        else b.at(1) = c.at(1);
      }
    }
    
    if (d.at(2) == 4) {
      if (d.at(1) < c.at(1)) {
        if (d.at(1) >= b.at(1)) c.at(1) = d.at(1);
        else c.at(1) = b.at(1);
      }
    }
  }
  
  cout << (c.at(0)-b.at(0))*(c.at(1)-b.at(1));
}