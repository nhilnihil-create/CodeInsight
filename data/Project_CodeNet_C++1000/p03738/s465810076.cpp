#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  if(s.size()>t.size()) {
    cout << "GREATER" << endl;
    return 0;
  }
  else if(s.size()<t.size()) {
    cout << "LESS" << endl;
    return 0;
  }
  for(int i=0; i<max(s.size(), t.size()); i++) {
    if(s.at(i)>t.at(i)) {
      cout << "GREATER" << endl;
      return 0;
    }
    else if(s.at(i)<t.at(i)) {
      cout << "LESS" << endl;
      return 0;
    }
  }
  cout << "EQUAL" << endl;
  return 0;
}