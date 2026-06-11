#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int ai = 1001001001;
  int zi = 0;
  rep(i, s.size()) {
    if (s[i] == 'A') {
      ai = min(ai, i);
    }
    if (s[i] == 'Z') {
      zi = max(zi, i);
    }
  }
  cout << zi - ai + 1 << endl;
  return 0;
}