#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main() {
  int W,H,N; cin >> W >> H >> N;
  vector<vector<bool>> black(100,vector<bool>(100,false));
  
  int ans =0;
  for (int i =0; i<N; i++) {
    int x,y,a; cin >> x >> y >> a;
    for (int j =0; j<H; j++) {
      for (int k =0; k<W; k++) {
        if (a == 1 && k < x) black[j][k] = true;
        if (a == 2 && k >= x) black[j][k] = true;
        if (a == 3 && j < y) black[j][k] = true;
        if (a == 4 && j >= y) black[j][k] = true;
      }
    }
  }
  
  for (int i =0; i<H; i++) {
    for (int j =0; j<W; j++) {
      if (black[i][j] == false) ans++;
    }
  }
                            
  cout << ans << endl;
}