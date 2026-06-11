#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  int l = 0, r = 0;
  rep(i, 0, n) {

    if (i != n - 1 && s[i] == '(' && s[i + 1] == ')')
      i++;
    else {
      if (s[i] == '(')
        r++;
      else {
        if (r > 0)
          r--;
        else
          l++;
      }
    }
  }

  cout << string(l, '(') << s << string(r, ')') << endl;
}
