#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int sum = a + b + c ;
  int average = sum / 2;
  
  if ( sum % 2 == 1 ){
    cout << "No";
  }
  else{
    if ( (average == a || average == b) || average == c ){
      cout << "Yes" ;
    }
    else {
      cout << "No" ;
    }
  }
}