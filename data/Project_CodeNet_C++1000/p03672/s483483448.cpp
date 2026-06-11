#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool gu(string s) {
  if (s.size() % 2 != 0) return false;
  return s.substr(0, s.size() / 2) == s.substr(s.size() / 2);
}

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (gu(s.substr(0, i))) ans = i;
  }
  cout << ans << endl;
  return 0;
}