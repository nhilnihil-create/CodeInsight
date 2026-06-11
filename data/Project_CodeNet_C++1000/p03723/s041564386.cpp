#include <iostream>
 
using namespace std;
 
int find (int a, int b, int c) {
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    return 0;
  } else {
    return find((a + b) / 2, (a + c) / 2, (b + c) / 2) + 1;
  }
}
 
int main () {
  int a, b, c;
  cin >> a >> b >> c;
  
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    cout << 0 << endl;
  } else if (a == b & b == c) {
    cout << -1 << endl;
  } else {
    cout << find(a, b, c) << endl;
  }
}
