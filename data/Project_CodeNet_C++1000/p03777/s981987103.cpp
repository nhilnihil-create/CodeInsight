#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  string a, b;
  cin >> a >> b;

  if (a == "H") {
    if (b == "H")
      cout << "H" << endl;
    else
      cout << "D" << endl;
  }

  else if (a == "D") {
    if (b == "H")
      cout << "D" << endl;
    else
      cout << "H" << endl;
  }

  return 0;
}
