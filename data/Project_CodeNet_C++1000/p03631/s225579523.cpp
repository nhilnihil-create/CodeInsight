#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string digit;
  
  cin >> digit;
  
  if(digit.at(0) == digit.at(2)) {
    
    cout << "Yes" << endl;
    
  } else if(digit.at(0) != digit.at(2)) {
    
    cout << "No" << endl;
    
  }
  
  return 0;
  
}