#include <bits/stdc++.h>
using namespace std;
int main(){
  string alf = "abcdefghijklmnopqrstuvwxyz";
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int p = 0, l = s.size();
  string ans = "";
  for(int i=0; i<26; ++i){
    bool e = false;
    for(int j=p; j<l; ++j){
      if(alf[i] == s[j]) e = true;
      if(alf[i] < s[j]){
        if(!e) ans.push_back(alf[i]);
        p = j;
        break;
      }
    }
    if(!e) ans.push_back(alf[i]);
  }
  if(ans.size()) cout << ans[0] << endl;
  else cout << "None" << endl;
}