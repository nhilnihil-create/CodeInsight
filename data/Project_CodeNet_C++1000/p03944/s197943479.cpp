#include <bits/stdc++.h>
using namespace std;
int main(){
  int w, h ,n;
  cin >> w >> h >> n;
  vector<vector<int>> m(h, vector<int>(w));
  int x, y, a;
  for(int i=0; i<n; ++i){
    cin >> x >> y >> a;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(a == 1 && j < x) m[i][j] = 1;
        if(a == 2 && j >= x) m[i][j] = 1;
        if(a == 3 && i < y) m[i][j] = 1;
        if(a == 4 && i >= y) m[i][j] = 1;
      }
    }
  }
  int ans = 0;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j) if(!m[i][j]) ++ans;
  }
  cout << ans << endl;
}