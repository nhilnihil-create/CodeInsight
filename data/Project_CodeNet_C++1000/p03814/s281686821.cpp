#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string s;
  cin >> s;

  int ans = 0;
  int apos = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'A') {
      apos = i;
      break;
    }
  }
  int zpos = 0;
  for (int i = s.length() - 1; i > apos; --i) {
    if (s[i] == 'Z') {
      zpos = i;
      break;
    }
  }

  cout << (zpos - apos + 1) << endl;
  
  return 0;
}