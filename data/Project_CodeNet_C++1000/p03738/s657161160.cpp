#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  string s, t;
  cin >> s >> t;
  if(s.size()>t.size()) cout << "GREATER" << endl;  
  else if(t.size()>s.size()) cout << "LESS" << endl;
  else {
    for(int i=0; i<s.size(); i++) {
      if(s[i]>t[i]) {
        cout << "GREATER" << endl;
        break;
      }
      else if(s[i]<t[i]) {
        cout << "LESS" << endl;
        break;
      }
      if(i==s.size()-1) cout << "EQUAL" << endl;
    }
  }
  return 0;
}