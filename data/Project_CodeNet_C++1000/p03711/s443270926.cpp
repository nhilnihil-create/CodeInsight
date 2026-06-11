#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int select(int a) {
  int b;
  if (a == 2)
    b = 0;

  else if (a == 4 || a == 6 || a == 9 || a == 11)
    b = 1;
  else
    b = 2;
  return b;
}

int main() {
  int x, y;

  cin >> x >> y;

  x = select(x);
  y = select(y);

  if (x == y)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
