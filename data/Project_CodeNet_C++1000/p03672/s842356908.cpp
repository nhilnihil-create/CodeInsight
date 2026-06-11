#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  bool flag = 0;
  for(int i = s.size()-1; ; i = s.size()-1) {
    s.erase(i,1);
    for(int j = 0; j < s.size()/2; j++) {
      if(s.size() % 2 != 0) {
        flag = 0;
        break;
      }
      else {
        if(s[j] != s[s.size()/2+j]) {
          flag = 0;
          break;
        }
        else flag = 1;
      }
    }
    if(flag) {
      cout << s.size() << endl;
      return 0;
    }
  }

  
}
