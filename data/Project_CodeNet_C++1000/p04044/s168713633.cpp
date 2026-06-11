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
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, n) {
    string st;
    cin >> st;
    s.at(i) = st;
  }
  sort(s.begin(), s.end());
  rep(i, n) {
    cout << s.at(i);
  }
  cout << endl;
}
