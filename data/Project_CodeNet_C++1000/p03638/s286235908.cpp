#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
void solve(){
  int h, w, n; cin >> h >> w >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  vector<vector<int> > c(h, vector<int>(w));
  int cnt = 0, num = 1;
  for(int i = 0; i < h; i++){
    if(i % 2 == 0){
      for(int j = 0; j < w; j++){
        c[i][j] = num;
        cnt++;
        if(a[num] <= cnt){
          num++;
          cnt = 0;
        }
      }

    }
    else{
      for(int j = w - 1; j >= 0; j--){
        c[i][j] = num;
        cnt++;
        if(a[num] <= cnt){
          num++;
          cnt = 0;
        }
      }
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}
