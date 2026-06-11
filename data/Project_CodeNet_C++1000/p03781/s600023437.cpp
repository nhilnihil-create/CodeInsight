#include <iostream>
using namespace std;

int main() {
  int X;
  cin >> X;
  int t = 0, sum = 0;
  while (sum < X) {
    sum += t + 1;
    t++;
  }
  cout << t << endl;
  return 0;
}