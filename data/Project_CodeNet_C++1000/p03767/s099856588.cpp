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
  int n;
  cin >> n;
  vector<int> a(3*n);
  rep(i, 3*n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  int64_t sum = 0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int count = 1;
  rep(i, n) {
    sum += a.at(count);
    count += 2;
  }
  cout << sum << endl;
}
