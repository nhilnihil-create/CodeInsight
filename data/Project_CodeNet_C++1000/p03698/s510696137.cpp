#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> used(26, false);
  bool varied = true;
  rep(i, s.size()) {
    if (used[s[i]-'a']) varied = false;
    used[s[i]-'a'] = true;
  }
  if (varied) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}