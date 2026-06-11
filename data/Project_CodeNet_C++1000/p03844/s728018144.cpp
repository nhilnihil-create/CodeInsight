#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  string S; 
  cin >> A >> S >> B;
  
  if(S == "+")
    cout << A + B << endl;
  else
    cout << A - B << endl;
  
  
  return 0;
}
