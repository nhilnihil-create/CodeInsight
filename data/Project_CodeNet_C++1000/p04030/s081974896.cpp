#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  string t;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='0' || s[i]=='1') t += s[i];
    else if(t.size() > 0) t.pop_back();
  }
  cout << t << endl;
  return 0;
}