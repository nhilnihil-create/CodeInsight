#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }
  bool allExists = true;
  for (char i = 'a'; i <= 'z'; i++) {
    if (mp[i] == 0) {
      cout << i << endl;
      allExists = false;
      break;
    }
  }
  if (allExists) {
    cout << "None" << endl;
  }
  return 0;
}
