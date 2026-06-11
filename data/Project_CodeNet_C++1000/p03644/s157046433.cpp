#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  if (x < 2) {
    cout << 1;
  }else if (x < 4) {
    cout << 2;
  }else if (x < 8) {
    cout << 4;
  }else if (x < 16) {
    cout << 8;
  }else if (x < 32) {
    cout << 16;
  }else if (x < 64) {
      cout << 32;
  }else {
      cout << 64;
  }
}