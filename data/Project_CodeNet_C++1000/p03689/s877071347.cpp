#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const int INF = 1e9;

int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if(H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  } 
  cout << "Yes" << endl;
  int a = (INF-1)/(h*w);
  rep(i,H) {
    rep(j,W) {
      if(i % h == h-1 && j % w == w-1) cout << -a*(h*w-1)-1 << " ";
      else cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}