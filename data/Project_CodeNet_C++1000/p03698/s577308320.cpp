#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, ans="yes";
  cin >> s;

  char c = s[0];

  for(int i = 0;i < s.size();i++){
    int t = i;
    for(int j = i+1;j < s.size();j++){
      if(s[i] == s[j]){
	ans = "no";
      }
    }
  } 

  cout << ans << endl;
  
  return 0;
}
