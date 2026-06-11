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

  string s1, s2;
  do {
    s.resize(s.length() - 2);
    s1 = s.substr(0, s.length() / 2);
    s2 = s.substr(s.length() / 2, s.length() / 2);
  } while (s1 != s2);

  cout << s.length() << endl;
  
  return 0;
}