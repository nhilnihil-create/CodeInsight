#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  bool check = false;
  while(0<s.size()) {
    //cout << s << endl;
    
    if(s.size()<5) {
      check = true;
      break;
    }
    
    if(s[4]=='m') {
      if(s.size()>7) {
        if(s.substr(0,7)=="dreamer" && s[7]=='a') {s = s.substr(5); continue;}
        else if(s.substr(0,7)=="dreamer" && s[7]!='a') {s = s.substr(7); continue;}
        else if(s.substr(0,5)=="dream") {s = s.substr(5); continue;}
        else check = true;
      }
      else if(s=="dream") {s = ""; continue;}
      else if(s=="dreamer") {s = ""; continue;}
      else check = true;
    }
    
    else {
      if(s.size()>6) {
        if(s.substr(0,6)=="eraser") {s = s.substr(6); continue;}
        else if(s.substr(0,5)=="erase") {s = s.substr(5); continue;}
        else check = true;
      }
      else if(s=="erase") {s = ""; continue;}
      else if(s=="eraser") {s = ""; continue;}
      else check = true;
    }
    
    if(check) break;
  }
  
  if(check) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}