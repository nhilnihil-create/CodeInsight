#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'A') {
      for(int j = s.size()-1; j > i; j--) {
        if(s[j] == 'Z') {
          sum = j+1-i;
          cout << sum << endl;
          return 0;
        }
      }
    }
  } 
}