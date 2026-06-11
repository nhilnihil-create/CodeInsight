#include <bits/stdc++.h>
using namespace std;

int main(){

  string s;
  cin >> s;
  int ct[26] = {};

  for(auto x:s)
    ct[x-'a']++;

  string res = "Yes";
  for(auto x:ct){
    if (x % 2 == 1){
      res = "No";
      break;
    }
  }
  cout << res << endl;
  
  return 0;
}