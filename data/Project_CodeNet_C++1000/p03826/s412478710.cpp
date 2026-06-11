#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  long A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A * B > C * D)
    cout << A * B << endl;
  else
    cout << C * D << endl;

  return 0;
}
