#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int count = s.size();
  // string s1 = s.substr(0,s.size()/2);
  // string s2 = s.substr(s.size()/2,s.size()/2);
  // cout << s1 << endl;
  // cout << s2 << endl;

  while (count > 0) {
    count--;
    string S = s.substr(0,count);
    if (s.size()%2 != 0) continue;
    string s1 = S.substr(0,S.size()/2);
    string s2 = S.substr(S.size()/2,S.size()/2);
    if (s1 == s2) {
      // cout << s1 << endl;
      // cout << s2 << endl;
      cout << s1.size()+s2.size() << endl;
      return 0;
    }
  }

}
