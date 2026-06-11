#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
 
  double max = 0;
  int water = 0;
  int sugar = 0;
  for (int ai = 0; 100 * a * ai <= f; ++ai) {
    for (int bi = 0; 100 * b * bi <= f; ++bi) {
      for (int ci = 0; c * ci <= f; ++ci) {
        for (int di = 0; d * di <= f; ++di) {
          int x = c * ci + d * di;
          int y = 100 * a * ai + 100 * b * bi;
          double noudo = (double)x / (x + y);
          if (noudo > max && x + y <= f && x <= e*y / 100) {
            max = noudo;
            water = y;
            sugar = x;
          }
        }
      }
    }
  }
  if (sugar == 0) water = 100 * a;
  cout << water + sugar << " " << sugar << endl;
}