#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,t = "";
  cin >> s;
  
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') t += "0";
    if(s[i] == '1') t += '1';
    if(s[i] == 'B') {
      if(t.size() == 0) continue;
      else t.erase(t.size()-1,1);
    }
  }
  cout << t << endl;
}