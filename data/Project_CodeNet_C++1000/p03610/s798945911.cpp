#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s;
  for(int i=0; i<s.size(); i+=2) t+=s[i];
  cout << t << endl;
  return 0;
}