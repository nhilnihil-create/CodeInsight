#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  vector<int> count(26,0);
  
  for (int i = 0; i < s.length(); i++) {
    int temp = s[i] - 'a';
    count[temp] ++;
  }
  
  bool ans = true;  
  for (int i = 0; i < 26; i++) {
    if (count[i] >= 2)
      ans = false;
  }
  
  if (ans)
    cout << "yes";
  else
    cout << "no";
  
}