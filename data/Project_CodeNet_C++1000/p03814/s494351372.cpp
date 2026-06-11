#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  int start, end;
  
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A') {
      start = i;
      break;
    }
  }
  
  for (int i = s.size()-1; i >= 0; i--) {
    if (s.at(i) == 'Z') {
      end = i;
      break;
    }
  }
  
  cout << end - start + 1;
      
}