#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  string yaki = "YAKI";
  if (s.size() >= 4) {
    bool y = true;
    rep(i, 4) if (s[i] != yaki[i]) y = false;
    if (y) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}