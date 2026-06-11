#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int w = tx - sx;
  int h = ty - sy;

  rep(i, h) printf("U");
  rep(i, w) printf("R");
  rep(i, h) printf("D");
  rep(i, w) printf("L");
  printf("L");
  rep(i, h + 1) printf("U");
  rep(i, w + 1) printf("R");
  printf("DR");
  rep(i, h + 1) printf("D");
  rep(i, w + 1) printf("L");
  printf("U\n");
}
