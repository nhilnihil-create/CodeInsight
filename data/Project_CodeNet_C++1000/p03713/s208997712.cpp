#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  long long int h, w; cin >> h >> w;
  long long int ans = 10000000000;
  for(int i = 1; i < w; i++){
    vector<long long int> a(3);
    a[0] = h * i;
    if((w - i) % 2 != 0 && h % 2 != 0){
      if((w - i) < h){
        a[1] = (h / 2 + 1) * (w - i);
        a[2] = (h / 2) * (w - i);
      }
      else{
        a[1] = ((w - i) / 2 + 1) * h;
        a[2] = (w - i) / 2 * h;
      }
    }
    else{
      a[1] = a[2] = (w - i) * h / 2;
    }
    long long int maxa = max(a[0], a[1]), mina = min(a[0], a[2]);
    ans = min(maxa - mina, ans);
  }
  for(int i = 1; i < h; i++){
    vector<long long int> a(3);
    a[0] = w * i;
    if((h - i) % 2 != 0 && w % 2 != 0){
      if((h - i) < w){
        a[1] = (w / 2 + 1) * (h - i);
        a[2] = (w / 2) * (h - i);
      }
      else{
        a[1] = ((h - i) / 2 + 1) * w;
        a[2] = (h - i) / 2 * w;
      }
    }
    else{
      a[1] = a[2] = (h - i) * w / 2;
    }
    long long int maxa = max(a[0], a[1]), mina = min(a[0], a[2]);
    ans = min(maxa - mina, ans);
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
