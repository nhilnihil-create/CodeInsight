#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const int MAX_ALPHA = 26;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  rep(i, 0, n) {
    if (MAX_ALPHA - (s[i] - 'a') > k)
      continue;
    if (s[i] != 'a') {
      k -= MAX_ALPHA - (s[i] - 'a');
      s[i] = 'a';
    }
  }

  if (k != 0)
    s[n - 1] = (char)(((s[n - 1] - 'a') + k) % 26 + 'a');

  cout << s << endl;
}
