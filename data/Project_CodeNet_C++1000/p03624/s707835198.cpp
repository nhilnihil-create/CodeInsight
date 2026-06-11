#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,t;
  cin >> s;

  bool flag = 0;
  for(char ch = 'a'; ch <= 'z'; ch++) {
    for(int i = 0; i < s.size(); i++) {
      if(ch == s[i]) {
        flag = 0;
        break;
      }
      else flag = 1;
    }
    if(flag) {
      cout << ch << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}