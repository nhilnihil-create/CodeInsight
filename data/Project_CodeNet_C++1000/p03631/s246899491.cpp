#include <bits/stdc++.h>
using namespace std;
int main(){
 int A;
 cin >> A;
  
  int B = A%10;
  int C = A/100;
  
  if (B == C)
    cout << "Yes" << endl;
  else 
    cout << "No" <<endl;

}