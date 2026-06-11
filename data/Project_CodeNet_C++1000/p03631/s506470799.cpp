#include <bits/stdc++.h>
using namespace std;

bool pal(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string S;
  cin >> S;
  cout << ((pal(S)) ? "Yes" : "No") << "\n";
}