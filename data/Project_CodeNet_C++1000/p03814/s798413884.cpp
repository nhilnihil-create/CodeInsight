#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = s.size();
  int r = 0;
  
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A') l = min(i, l);
    if (s.at(i) == 'Z') r = max(i, r);
  }
  
  cout << r - l + 1 << endl;
}