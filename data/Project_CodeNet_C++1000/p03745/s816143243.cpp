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
  vector<int64_t> a(n);
  rep(i, n) {
    int64_t num;
    cin >> num;
    a.at(i) = num;
  }
  int count = 1;
  string now = "end";
  for (int i = 0; i < n-1; i++) {
    if (now == "end") {
      if (a.at(i) < a.at(i+1)) {
        now = "increase";
      }
      else if (a.at(i) > a.at(i+1)) {
        now = "decrease";
      }
    }
    else if (now == "increase") {
      if (a.at(i) > a.at(i+1)) {
        count++;
        now = "end";
      }
    }
    else if (now == "decrease") {
      if (a.at(i) < a.at(i+1)) {
        count++;
        now = "end";
      }
    }
  }
  cout << count << endl;
}

