#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int max_value = max(max(a, b), c);

  if ((max_value == a + b) || (max_value == b + c) || (max_value == a + c))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
