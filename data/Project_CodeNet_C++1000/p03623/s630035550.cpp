#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(abs(a-b) > abs(a-c)) {
    cout << "B\n";
  } else {
    cout << "A\n";
  }
}
