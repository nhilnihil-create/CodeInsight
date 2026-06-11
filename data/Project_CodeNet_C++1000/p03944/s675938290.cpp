#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
#define rep2(i, ns, ne) for (int i = ns; i <= ne; ++i)
using namespace std;

int H, W, N;
vector<vector<bool>> v;

void func(int y, int x, int a) {
  int sx, ex, sy, ey;
  if (a == 1) {
    sy = 1;
    ey = H;
    sx = 1;
    ex = x;
  } else if (a == 2) {
    sy = 1;
    ey = H;
    sx = x + 1;
    ex = W;
  } else if (a == 3) {
    sy = 1;
    ey = y;
    sx = 1;
    ex = W;
  } else if (a == 4) {
    sy = y + 1;
    ey = H;
    sx = 1;
    ex = W;
  }
  rep2(i, sy, ey) {
    rep2(j, sx, ex) {
      v[i][j] = false;
    }
  }
}

void prtALl() {
  for (auto h : v) {
    for (bool w : h) {
      if (w) {
        cout << "@";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}

int main() {
  cin >> W >> H >> N;
  v.resize(H + 1, vector<bool>(W + 1, true));
  rep(i, 0, H + 1) { v[i][0] = false; }
  rep(i, 0, W + 1) { v[0][i] = false; }

  int x, y, a;
  rep(i, 0, N) {
    cin >> x >> y >> a;
    func(y, x, a);
  }

  int ans = 0;
  for (auto h : v) {
    for (bool w : h) {
      if (w) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  getchar();
}