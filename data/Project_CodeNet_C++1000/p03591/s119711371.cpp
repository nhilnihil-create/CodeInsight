#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.size() > 3 && s.substr(0, 4) == "YAKI")
    puts("Yes");
  else
    puts("No");
}