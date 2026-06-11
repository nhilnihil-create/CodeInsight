#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string w;
  cin >> w;
  bitset<26> s;
  for (auto c : w) {
    if (s.test(c-'0'-49)) s.set(c-'0'-49, 0);
    else s.set(c-'0'-49, 1);
  }
  cout << (!s.any() ? "Yes" : "No") << endl;
}