#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  string ans = s;
  for(int i=0; i<n; ++i){
    if(s[i] == '(') ++cnt;
    else{
      --cnt;
      if(cnt <0){
        ans = '(' + ans;
        ++cnt;
      }
    }
  }
  while(cnt>0){
    ans += ')';
    --cnt;
  }
  cout << ans << endl;
}