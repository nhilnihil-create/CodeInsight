#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s, ans;
  cin >> s;
  
  for (char x : s){
    if (x == '0') ans += "0";
    if (x == '1') ans += "1";
    if (x == 'B' && !ans.empty()) ans.pop_back();
  }
  
  cout << ans << endl;
}