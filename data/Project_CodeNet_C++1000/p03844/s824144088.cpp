#include <iostream>

using namespace std;

int main(){
  int A,B;
  char op;
  cin >> A >> op >> B;
  
  if(op == '+')
    cout << A + B;
  else
    cout << A - B;
}