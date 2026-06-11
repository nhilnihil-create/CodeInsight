#include <bits/stdc++.h>
using namespace std;

bool dfs(string &s, int p){
  if(s.size() == p)
    return true;
  
  bool r = false;
  string words[] = {"dream", "dreamer", "erase", "eraser"};
  for(int i=0; i<4; i++){
    bool ok = true;
    for(int j=0; j<words[i].size(); j++)
      if(words[i][j] != s[p+j]){
        ok = false;
        break;
      }
    if(ok)  r = r || dfs(s, p+words[i].size());
  }
  return r;
}

int main(){
  string s;  cin >> s;
  string ans = "NO";
  if(dfs(s, 0))  ans = "YES";
  cout << ans << endl;
  return 0;
}
