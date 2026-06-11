#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  set<char> ss;
  for (int i = 0; i < s.size(); ++i) {
    ss.insert(s[i]);
  }

  for (char i = 'a'; i <= 'z'; ++i) {
    if (ss.count(i) == 0) {
      cout << i << '\n';
      return 0;
    }
  }

  cout << "None" << '\n';
  return 0;
}