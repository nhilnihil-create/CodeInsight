#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string w;
  cin >> w;

  map<char, int> mp;
  rep(i, w.size()) mp[w[i]]++;

  for (auto x : mp) {
    if (x.second % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}