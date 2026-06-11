#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,m;
  cin >> s;
  
  for (int i = 0; i < s.size(); i++) {
    if(s.at(i) == '0'){
      m.push_back('0');
    }
    if(s.at(i) == '1'){
      m.push_back('1');
    }
    if(s.at(i) == 'B'){
      if(m.size() > 0){
        m.pop_back();
      }
    }
  }
        
  cout << m << endl;
  
}
  