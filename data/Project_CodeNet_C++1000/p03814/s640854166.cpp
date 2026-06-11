#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int a=s.size(), z=0;
  for(int i=0; i<s.size(); i++) {
    if(a>i && s[i]=='A') a=i;
    if(z<i && s[i]=='Z') z=i;
  }
  cout << z-a+1 << endl;
  return 0;
}