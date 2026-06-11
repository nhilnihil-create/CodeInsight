#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string s;
  cin >> s;

  int n = s.size();
  int answer = 0;
  for (int i = n - 1; i >= 0; i--) {
    string tmp = s.substr(0, i);
    if(tmp.size() % 2 != 0) continue;

    string left = tmp.substr(0, tmp.size()/2);
    string right = tmp.substr(tmp.size()/2, tmp.size()/2);
    if(left == right) {
      answer = i;
      break;
    }
  }

  cout << answer << endl;

  return 0;
}