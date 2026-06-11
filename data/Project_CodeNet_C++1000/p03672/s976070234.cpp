#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 0;
  
  while (true) {
    string a, b;
    s.erase(s.begin() + s.size() - 1);
    res++;

    if (s.size() % 2 != 0) continue;
    a = s.substr(0, s.size() / 2);
    b = s.substr(s.size() / 2, s.size());
    if (a == b) {
      break;
    }
  }
  printf("%d\n",s.size());

  return 0;
}
