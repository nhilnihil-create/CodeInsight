#include <bits/stdc++.h>
using namespace std;


void solve() {
  int W, H, N;
  cin >> W >> H >> N;
  int x1 = 0, x2 = W + 1, y1 = 0, y2= H + 1;
  int x , y , a;
  for (int i = 1; i <= N; i++) {
    cin >> x >> y >> a;
    if(a == 1) {
      x1 = max(x1, x);
    }
    else if (a == 2) {
      x2  = min(x2, x);
    }
    else if (a == 3) {
      y1 = max(y1, y);
    }
    else if ( a == 4) {
      y2 = min(y2, y);
    }
  }
  //cout << x1 << " " << x2 << "\n";
  //cout << y1 << " " << y2 << "\n";
  if(x2 <= W){
    W = x2;
  }
  W -= x1;
  if(y2 <= H) {
    H = y2;
  }
  H -= y1;
  //cout << W << " " << H << endl;
  if(W <= 0 || H <= 0) {
    cout << 0;
  }
  else {
    cout << W*H;
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
