#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  string ans;
  cin >> s;
  for(int i = 0; i < s.size() ; i++){
    if(s[i] =='B' && ans.size() != 0)
      ans.erase(ans.size() - 1);
    else if(s[i] != 'B')
      ans = ans + s[i];
  }
  
  cout << ans << endl;
}