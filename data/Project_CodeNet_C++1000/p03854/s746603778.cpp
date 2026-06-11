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
  string s;
  cin >> s;
  vector<string> words(4);
  words.at(0) = "dream";
  words.at(1) = "dreamer";
  words.at(2) = "erase";
  words.at(3) = "eraser";
  reverse(s.begin(), s.end());
  rep(i, 4) {
    reverse(words.at(i).begin(), words.at(i).end());
  }
  int size = s.size();
  string cal;
  int count = 0;
  for (int i = 0; i < size; i++) {
    cal += s.at(i);
    rep(j, 4) {
      if ((string)cal == words.at(j)) {
        cal = "";
      }
    }
    //cout << cal << endl;
  }
  if (cal == "") {
    coYES;
  }
  else {
    coNO;
  }
}
