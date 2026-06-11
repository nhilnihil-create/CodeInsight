#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t="";
  cin >> s;
  int len = s.size();
  for(int i=0; i<len; i++){
    if(s[i]=='0')
      t.push_back('0');
    else if(s[i]=='1')
      t.push_back('1');
    else if(!t.empty())
      t.pop_back();
  }
  cout << t;
  return 0;
}