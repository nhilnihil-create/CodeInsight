#include <iostream>
using namespace std;
 
int main() {
 int x, y;
 cin >> x >> y;
 if (x == 1) {
   x = 14;
 }
 if (y == 1) {
   y = 14;
 }
 if (x > y) {
   cout << "Alice";
 }
  else if (y > x) {
   cout << "Bob";
  }
  else {
    cout << "Draw";
  }
}