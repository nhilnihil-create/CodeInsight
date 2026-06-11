#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  rep(i, s.size() - 1) {
    char c = s[i];
    if (c == 'a') {
      cout << 'a';
      continue;
    }
    if (c + k > 'z') {
      k -= (ll)('z' - c + 1);
      cout << 'a';
    } else {
      cout << c;
    }
  }
  char c = s[s.size() - 1];
  if (c + k > 'z') {
    k -= (ll)('z' + 1 - c);
    c = 'a';
  } else {
    c += k;
    k = 0;
  }
  cout << (char)(c + k % 26) << endl;

  return 0;
}
