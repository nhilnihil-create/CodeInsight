#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  
  char g = 'A';
  
  
  for (int i = 0; i < 3; i++) {
    
    cin >> s;
    
    if (s.at(0) == 'A' && !(i == 1)) {
      
      continue;
      
    }
    else if (s.at(0) == 'C' && !(i == 1)) {
      
      continue; 
      
    }
    else {
      
      g = s.at(0);
      
      
      
      break;
      
    }
  }
  cout << "A"  << g << "C" <<endl;
}