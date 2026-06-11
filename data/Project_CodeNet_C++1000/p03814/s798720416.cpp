#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
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
  int size = s.size();
  int sita = -1;
  int ue = -1;
  rep(i, size) {
    if (s.at(i) == 'A') {
      sita = i;
      break;
    }
  }
  reverse(s.begin(), s.end());
  rep(i, size) {
    if (s.at(i) == 'Z') {
      ue = i;
      break;
    }
  }
  cout << size - sita -ue << endl;
}
  
      
      
