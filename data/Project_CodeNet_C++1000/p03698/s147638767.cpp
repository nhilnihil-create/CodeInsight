#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  vector<bool> seen(26, false);
  char c;
  bool flag = true;
  while (cin >> c) {
    if (seen[c-'a']) flag = false;
    seen[c-'a'] = true;
  }
  cout << (flag ? "yes" : "no") << endl;
  return 0;
}