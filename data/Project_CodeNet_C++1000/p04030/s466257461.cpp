#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s; cin >> s;
  
  vector<char> vec(0);
  
  for (int i = 0; i < s.size(); i++) {
    
    char tmp = s.at(i);
    
    if (tmp == '0') vec.push_back('0');
    
    if (tmp == '1') vec.push_back('1');
    
    if (tmp == 'B') {
      if (vec.size() == 0) continue;
      vec.pop_back();
    }
    
  }
  
  for (auto x : vec) cout << x;
  
  cout << endl;
  
}