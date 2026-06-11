#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int h, w;
  cin >> h >> w;
  char c[h][w];
  rep(i,h) {
    rep(j,w) {
      cin>> c[i][j];
    }
  }
  rep(i,h) {
    rep(j,w) {
      cout << c[i][j];
    }
    cout << endl;
    rep(j,w) {
      cout << c[i][j];
    }
    cout << endl;
  }
}