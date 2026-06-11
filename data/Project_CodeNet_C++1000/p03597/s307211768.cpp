#include <bits/stdc++.h>
using namespace std;

int main() {
  int side, square, white, black;
  cin >> side  >> white;
  square = side * side;
  black = square - white;
  cout << black << endl;
}