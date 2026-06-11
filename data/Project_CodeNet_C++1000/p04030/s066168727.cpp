#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  string t = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0')
    {
      t += '0';
    } else if (s[i] == '1') {
      t += '1';
    } else if (s[i] == 'B' && t == "") {
      continue;
    } else {
      t.pop_back();
    }
  }
  cout << t << endl;
  return 0;
}