#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  set<int> s1;
  s1.insert(0);
  set<int> s2;
  s2.insert(w);
  set<int> s3;
  s3.insert(0);
  set<int> s4;
  s4.insert(h);

  for (int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      s1.insert(x);
    }
    if (a == 2) {
      s2.insert(x);
    }
    if (a == 3) {
      s3.insert(y);
    }
    if (a == 4) {
      s4.insert(y);
    }
  }
  int lx = *s1.rbegin();
  int ux = *s2.begin();
  int ly = *s3.rbegin();
  int uy = *s4.begin();
  if (ux - lx <= 0 || uy - ly <= 0) {
    cout << 0 << endl;
  } else {
    cout << (ux - lx) * (uy - ly) << endl;
  }
}
