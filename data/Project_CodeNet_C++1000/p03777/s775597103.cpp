#include <iostream>
using namespace std;

int main() {
  char atDeer, topDeer; cin >> atDeer >> topDeer;
  if (atDeer == 'H') {
    cout << topDeer;
  } else {
    if (topDeer == 'H') {
      cout << 'D';
    } else {
      cout << 'H';
    }
  }
}