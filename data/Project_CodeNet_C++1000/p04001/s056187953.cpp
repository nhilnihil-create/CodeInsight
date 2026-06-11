#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  string item;
  for (char ch : s) {
    if (ch == delim) {
      if (!item.empty()) elems.push_back(item);
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty()) elems.push_back(item);
  return elems;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  ll ans = 0;

  // 先頭に + が挿入されることはないので (n - 1) 箇所の隙間が対象
  rep(bit, 1 << (n - 1)) {
    ll tmp = 0;
    for (int i = 0; i < n - 1; i++) {
      tmp *= 10;
      tmp += s[i] - '0';
      if (bit >> i & 1) {
        ans += tmp;
        tmp = 0;
      }
    }
    tmp *= 10;
    tmp += s.back() - '0';
    ans += tmp;
  }

  cout << ans << endl;

  return 0;
}
