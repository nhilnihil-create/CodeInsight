#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i >= n; --i)
typedef long long ll;
#define mod 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
  string s; cin >> s;
  rep(i, 0, 4) cout << s[i];
  cout << " ";
  rep(i, 4, 12) cout << s[i];
  cout << endl;
  return 0;
}
