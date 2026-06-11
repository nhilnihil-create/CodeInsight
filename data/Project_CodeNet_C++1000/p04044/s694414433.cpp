#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end());
  string ans;
  rep(i, n) ans += s[i];
  cout << ans << endl;
}