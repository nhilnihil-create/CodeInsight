#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0;
  int max_x = 0;
  for (auto c : s) {
    x += (c == 'I' ? 1 : -1);
    max_x = max(max_x, x);
  }
  cout << max_x << endl;
}