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
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i, n) {
    int num;
    cin >> num;
    l.at(i) = num;
  }
  int sum = 0;
  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());
  rep(i, k) {
    sum += l.at(i);
  }
  cout << sum << endl;
}
