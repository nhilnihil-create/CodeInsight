#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int a, b;
  cin >> a >> b;

  if ((a == 0 || b == 0) || (a < 0 && b > 0))
    cout << "Zero" << endl;
  else if (a > 0 && b > 0)
    cout << "Positive" << endl;
  else if ((b - a) % 2 == 1)
    cout << "Positive" << endl;
  else
    cout << "Negative" << endl;

  return 0;
}