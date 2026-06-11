#include <iostream>
using namespace std;

int main (){
  int A, B;
  char op;
  cin >> A >> op >> B;
  if ( op == '+' ){
    cout << A + B << '\n';
  } else if ( op  == '-' ) {
    cout << A - B << '\n';
  }
}