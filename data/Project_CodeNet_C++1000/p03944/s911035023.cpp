#include <bits/stdc++.h>
using namespace std;


void solve() {
  int W, H, N;
  cin >> W >> H >> N;
  int x1 = 0, y1 = 0;
  int x , y , a;
  for (int i = 1; i <= N; i++) {
    cin >> x >> y >> a;
    if(a == 1 && x1 < x) {
      x1 = x;
    }
    else if (a == 2 && W > x) {
      W = x;
    }
    else if (a == 3 && y1 < y) {
      y1 = y;
    }
    else if (a == 4 && H > y) {
      H = y;
    }
  }
  W -= x1;
  H -= y1;
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
