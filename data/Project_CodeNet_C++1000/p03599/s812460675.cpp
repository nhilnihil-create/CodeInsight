#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  vector<int> water;
  for (int i = 0; i <= f/(100*a); i++) {
    for (int j = 0; j <= f/(100*b); j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (100*a*i +100*b*j > f) {
        break;
      }
      water.push_back(100*a*i + 100*b*j);
    }
  }
  
  vector<int> sugar;
  for (int i = 0; i <= (f/100)*e/c; i++) {
    for (int j = 0; j <= (f/100)*e/d; j++) {
      sugar.push_back(i*c + j*d);
    }
  }
  double max_con = -1, con;
  int max_water, max_sugar;
  
  for (double x : water) {
    for (double y : sugar) {
      if (x+y > f || y > (x/100)*e) continue;
      con = y/(x+y);
      if (con > max_con) {
        max_con = con;
        max_water = x;
        max_sugar = y;
      }
    }
  }
  printf("%d %d", max_water+max_sugar, max_sugar);
}