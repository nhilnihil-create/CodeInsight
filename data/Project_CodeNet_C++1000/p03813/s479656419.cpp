#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  long x;
  cin >> x;

  if (x < 1200)
    cout << "ABC" << endl;
  else
    cout << "ARC" << endl;

  return 0;
}
