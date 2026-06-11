#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  string s;
  cin >> s;
  set<char> t;
  for(int i=0; i<s.size(); i++) t.insert(s[i]);
  if(s.size()==t.size()) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}