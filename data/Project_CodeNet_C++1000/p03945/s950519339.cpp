#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s;
  cin >> s;

  int n1 = 0, n2 = 0;
  char f = s.front();
  for (auto iter = s.begin(); iter != s.end(); ++iter)
  {
    if (*iter != f) n1++;
    f = *iter;
  }

  char b = s.back();
  for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
  {
    if (*iter != b) n2++;
    b = *iter;
  }

  cout << min(n1, n2) << endl;
  return 0;
}
