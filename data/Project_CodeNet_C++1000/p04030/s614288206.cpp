#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string e = "";
 
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') {
      e.push_back('0');
    }
    else if(s[i] == '1') {
      e.push_back('1');
    }
    else if (s[i] == 'B' && e.size() > 0) {
      e.pop_back();
    }
  }
  cout << e << endl;
}