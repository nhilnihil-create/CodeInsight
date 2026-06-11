#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
  int h, w; cin >> h >> w;
  int n; cin >> n;
  int ans [h][w] = {};
  int x = 0;
  int y = 0;
  rep(i, n) {
    int num; cin >> num;
    while(num--){
      ans[y][x] = i + 1;
      if(y % 2 == 0) {
        if(x == w-1) y++;
        else x++;
      } else {
        if(x == 0) y++;
        else x--;
      }
    }
  }
  for(int i = 0; i<h; i++){
    for(int j = 0; j < w; ++j){
      (j == 0) ? cout << ans[i][j] : cout << " " << ans[i][j];
    }
    cout << endl;
  }
  return 0; 
}