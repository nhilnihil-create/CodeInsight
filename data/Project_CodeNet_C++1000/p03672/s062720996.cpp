#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int l = S.size();
  for (int i = 2 - l % 2; i <= l - 2; i = i + 2) {
    int sp = (S.size() - i) / 2;
    if (S.substr(0, sp) == S.substr(sp, sp)) {
      cout << S.size() - i << endl;
      return 0;
    }
  }
  return 0;
}