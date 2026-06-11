#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int l = 0, r = 0;
  int lcnt = 0, rcnt = 0;
  for(int i = 0; i < n-1; i++){
    if(s[i] == '(') lcnt++;
    if(s[i] == ')') rcnt++;
    if(s[i] != s[i+1]){
      if(lcnt > rcnt){
        continue;
      }
      if(lcnt < rcnt){
        l += rcnt - lcnt;
        lcnt = 0;
        rcnt = 0;
      }
    }
  }
  if(s[n-1] == '(') lcnt++;
  else{
    rcnt++;
    l += max(0, rcnt - lcnt);
  }
  r = max(lcnt - rcnt, 0);
  for(int i = 0; i < l; i++) cout << '(';
  cout << s;
  for(int i=  0; i < r; i++) cout << ')';
}