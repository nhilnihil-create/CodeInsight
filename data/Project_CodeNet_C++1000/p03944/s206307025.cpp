#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int x0 = 0, y0 = 0, W, H, N, x, y, a;
  cin >> W >> H >> N;
  while(cin >> x >> y >> a){
    if(a == 1 && x0 < x){
      x0 = x;
    } else if(a == 2 && W > x){
      W = x;
    } else if(a == 3 && y0 < y){
      y0 = y;
    } else if(a == 4 && H > y){
      H = y;
    }
  }
  int area = (W - x0) * (H - y0);
  if(W - x0 < 0 || H - y0 < 0){
    area = 0;
  }
  cout << area << endl;
}
