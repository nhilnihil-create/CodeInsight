#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; cin >> s;
  int g=0,p=0,ans=0;
  for(int i=0;i<s.size();++i) {
    if(s[i]=='g') {
      if(g>p) p++,ans++;
      else g++;
    } else {
      if(g>p) p++;
      else g++,ans--;
    }
  }
  cout << ans << endl;
  
  return 0;
}
