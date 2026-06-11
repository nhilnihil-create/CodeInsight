#include <iostream>
using namespace std;

int main(){
  string a, op, b;
  cin >> a >> op >> b;
  int i_a = atoi(a.c_str());
  int i_b = atoi(b.c_str());
  cout << (op == "+" ? i_a + i_b : i_a - i_b) << endl;
}