#include <iostream>
using namespace std;

int main() {
  int num_1, num_2, res;
  char op;
  cin >> num_1 >> op >> num_2;
  if(op == '+') res = num_1 + num_2;
  else res = num_1 - num_2;
  cout << res << endl;
}