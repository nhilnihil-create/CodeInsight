#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
 
int main() {
  int a, b, c, d, e, f, g, h, t, s1, s2;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100;
  b *= 100;
 
  for(int i = 0; i <= 30 && i*a <= f; ++i) {
    for(int j = 0; j <= 30 && j*b + i*a <= f; ++j) {
      if(i + j) {
        g = i*a + j*b;
        h = min(g*e/100, f-g);
        t = 0;
 
        for(int k = 0; k <= 100 && c*k <= h; k++) {
          for(int l = 0; l <= 100 && c*k + d*l <= h; l++) {
            t = max(t, c*k+d*l);
          }
        }
        if(s1 == 0 || t*(s1+s2) > s2*(g+t)) {
          s1 = g;
          s2 = t;
        }
      }
    }
  }
 
  cout << s1+s2 << " " << s2 << endl;
  return 0;
}