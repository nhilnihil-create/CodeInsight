#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  reverse(s.begin(), s.end());
  string a = "dream", b = "dreamer", c = "erase", d ="eraser";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());
  reverse(d.begin(), d.end());
  bool ok = true;
  string tmp = "";
  for(int i = 0; i < s.size(); i++){
    tmp += s[i];
    if(tmp.size() == a.size()){
      if(tmp == a || tmp == c) tmp = "";
    }
    if(tmp.size() == d.size()){
      if(tmp == d) tmp = "";
    }
    if(tmp.size() == b.size()){
      if(tmp == b) tmp = "";
      else{
        ok = false;
        break;
      }
    }
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}