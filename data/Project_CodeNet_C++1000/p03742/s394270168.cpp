#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long X, Y;

int main() {
  cin >> X >> Y;

  long long diff = (X > Y) ? X - Y : Y - X;

  if (diff > 1) {
    cout << "Alice" << endl;
  } else {
    cout << "Brown" << endl;
  }

  return 0;
}
