#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (char x : s) {
    if (x == ',') cout << ' ';
    else cout << x;
  }
}