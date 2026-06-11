#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  char ope;
  cin >> A >> ope >> B;
  
  int result;
  if( ope == '+' ){
    result = A + B;
  }
  else{
    result = A - B;
  }
  cout << result << endl;
}