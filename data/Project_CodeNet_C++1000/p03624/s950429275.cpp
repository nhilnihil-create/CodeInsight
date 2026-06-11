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
  map<char, int> alphabet;
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  rep(i, 26) {
    alphabet[alpha.at(i)] = 0;
  }
  int size = s.size();
  rep(i, size) {
    alphabet.at(s.at(i))++;
  }
  bool flag = true;
  rep(i, 26) {
    if (alphabet.at(alpha.at(i)) == 0) {
      cout << alpha.at(i) << endl;
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "None" << endl;
  }
}
