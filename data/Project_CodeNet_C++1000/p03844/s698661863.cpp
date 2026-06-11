#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  char op;
  int B;
  cin >> A >> op >> B;
  
  if( op == '+' ){
    A += B;
  }else{
    A -= B;
  }
  
  cout << A << endl;
}
