#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  int x = s.size()-2;
  cout << s[0] + to_string(x) + s[s.size()-1] << endl;
  return 0;
}