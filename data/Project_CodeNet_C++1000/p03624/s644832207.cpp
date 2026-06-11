#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string alp = "abcdefghijklmnopqrstuvwxyz";
  string str;
  cin >> str;
  int N = str.size();
  rep(i, N) {
    rep(j, 26) {
      if(str.at(i) == alp.at(j)) {
        alp.at(j) = '0';
      }
    }
  }
  int c = 0;
  rep(i, 26) {
    if(!(alp.at(i) == '0')) {
      cout << alp.at(i) << endl;
      break;
    }
    else {
      c++;
    }
    if(c == 26) {
      cout << "None" << endl;
    }
  }
}
