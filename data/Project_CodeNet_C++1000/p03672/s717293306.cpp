#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

bool isGu(const string& s) {
  if (s.length() % 2 != 0) return false;

  int half = s.length() / 2;
  string a = s.substr(0, half);
  string b = s.substr(half);
  return a == b;
}

int main() {
  string s;
  cin >> s;

  for (int i = 1; i < s.length(); i++) {
    int len = s.length() - i;
    string sub = s.substr(0, len);
    if (isGu(sub)) {
      cout << len << endl;
      return 0;
    }
  }
}
