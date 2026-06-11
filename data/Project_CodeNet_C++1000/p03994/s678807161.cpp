#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') continue;
    int t = 'z' + 1 - s[i];
    if (t > k) continue;
    s[i] = 'a';
    k -= t;
  }
  s[n - 1] = (s[n - 1] - 'a' + k) % 26 + 'a';
  cout << s << endl;
  return 0;
}
