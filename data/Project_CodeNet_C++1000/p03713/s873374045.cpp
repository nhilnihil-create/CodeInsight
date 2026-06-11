#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll h, w, m = 100000;
  cin >> h >> w;
  if(h % 3 && w % 3) {
    m = min(h, w);
    ll a, b, c;
    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < h % 3; i++) {
        ll l = h / 3 + i;
        a = l * w;
        if(w % 2) {
          b = (h - l) * (w / 2);
          c = (h - l) * (w / 2 + 1);
          ll ma = max(max(a, b), c), mi = min(min(a, b), c);
          m = min(ma - mi, m);
        } else {
          b = (h - l) * w / 2;
          m = min(abs(a - b), m);
        }
      }
      swap(h, w);
    }
    cout << m << endl;
  } else
    cout << 0 << endl;
}