#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
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
  cout << s.at(0) << size-2 << s.at(size-1) << endl;
}