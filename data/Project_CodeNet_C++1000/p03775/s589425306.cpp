#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int64_t n;
  cin >> n;
  int64_t a, b;
  int f_min = 10000;
  for (int64_t i = 1; i < 100001; i++) {
    a = i;
    if (n % a == 0) {
      b = n / a;
      //cout << a << " " << b << endl;
      int count_a = 0;
      int count_b = 0;
      while (a>0) {
        count_a++;
        a /= 10;
      }
      while (b>0) {
        count_b++;
        b /= 10;
      }
      int f = max(count_a, count_b);
      if (f_min > f) {
        f_min = f;
      }
    }
  }
  cout << f_min << endl;
}
    
