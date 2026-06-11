#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >>s;
  
  vector<bool> check(26, true);
  int num;
  
  for (int i = 0; i < s.size(); i++) {
    num = s[i] - 'a';
    check[num] = false;
  }
  
  bool fin = false;
  char ans;
  
  for (int i = 0; i < 26; i++) {
    if (check[i]) {
      ans = i + 'a';
      cout << ans;
      fin = true;
      break;
    }
  }
  
  if (!fin)
    cout << "None";
    
}