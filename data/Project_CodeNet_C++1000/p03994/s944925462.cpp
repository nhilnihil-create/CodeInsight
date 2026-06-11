#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int head(int n) {
  string s = to_string(n);
  return s[0] - '0';
}
int tail(int n) {
  string s = to_string(n);
  return s[s.length() - 1] - '0';
}

int main() {
  string s;
  ll k;
  cin >> s;
  cin >> k;

  int l = s.length();
  rep(i, l) {
    if (k == 0) break;
    if (s[i] == 'a') continue;
    int r = 'z' - s[i] + 1;
    if (k >= r) {
      k -= r;
      s[i] = 'a';
    }
  }
  k %= 26;
  rep(i, k) {
    s[l - 1]++;
    if (s[l - 1] > 'z') s[l - 1] = 'a';
  }
  cout << s << endl;
}
