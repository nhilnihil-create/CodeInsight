// ABC 063 B Varied

#include <bits/stdc++.h>
using namespace std;

bool is_not_duplicate(string str) {
  for (int i = 1; i < (int)str.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (str[i] == str[j]) return false;
    }
  }
  return true;
}

string solve(string str) {
  return is_not_duplicate(str) ? "yes" : "no";
}

int main() {
  string str;
  cin >> str;
  cout << solve(str) << endl;
  return 0;
}