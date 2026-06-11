#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  getline(cin, s);

  rep (i, s.size()) {
    if (s.at(i) == ' ') {
      cout << "A" << s.at(i+1) << "C" << endl;
      break;
    }
  }
}
