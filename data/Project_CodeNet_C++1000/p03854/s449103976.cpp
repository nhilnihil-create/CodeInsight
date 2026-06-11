#include <bits/stdc++.h>
using namespace std;

long b;
string s,ans;

bool c(string x) {
  if(x.size()>b) return false;
  for(long i=1;i<=x.size();i++) {
    if(s[b-i]!=x[x.size()-i]) return false;
  }
  return true;
}
 
int main() {
  cin >> s;
  b=s.size();
  while(true) {
    if(b==0) {
      ans="YES";
      break;
    } else if(c("dream")) {
      b-=5;
    } else if(c("dreamer")) {
      b-=7;
    } else if(c("erase")) {
      b-=5;
    } else if(c("eraser")) {
      b-=6;
    } else {
      ans="NO";
      break;
    }
  }
  
  cout << ans << endl;
}