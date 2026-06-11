#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  if (s.size() % 2 == 1) {
    s.erase(s.size() - 1);
  } else {
    s.erase(s.size() - 2, 2);
  }

  while (s.size() > 1) {
    int half = s.size() / 2;
    if (s.substr(0, half) == s.substr(half, half)) break;

    s.erase(s.size() - 2, 2);
  }

  cout << s.size() << endl;
  return 0;
}