#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n < 4) {
    puts("No");
    return 0;
  }

  string t = "YAKI";
  for (int i = 0; i < 4; ++i) {
    if (s[i] != t[i]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
