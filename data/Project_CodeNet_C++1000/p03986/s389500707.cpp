#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0, cnt = 0;
  for(int i=0; i<n; ++i){
    if(s[i] == 'T'){
      if(cnt) --cnt;
      else ans += 2;
    }else{
      ++cnt;
    }
  }
  cout << ans << endl;
}