#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s; cin >> s;
  
  bool flag = true; int ans = 100;
  
  for (int i = 0; i < s.size() - 1; i++) {
    
    if (s.at(i) != s.at(i + 1)) flag = false;
    
  }
  
  if (flag) { cout << 0 << endl; return 0; }
  
  for (int i = 0; i < s.size(); i++) {
    
    int count = 0;
    
    char target = s.at(i);
    
    string tmp = s, shaped = "";
    
    while (true) {
      
      count++;
      
      for (int j = 0; j < tmp.size() - 1; j++) {
        
        if (tmp.at(j) == target || tmp.at(j + 1) == target) {
          shaped = shaped + target;
        }
        
        else {
          shaped = shaped + tmp.at(j);
        }
        
      }
      
      string rightStr = "";
      
      for (int j = 0; j < shaped.size(); j++) rightStr = rightStr + target;
      
      if (rightStr == shaped) break;
      
      else { tmp = shaped; shaped = ""; }
      
    }
    
    ans = min(ans, count);
    
  }
  
  cout << ans << endl;
  
}