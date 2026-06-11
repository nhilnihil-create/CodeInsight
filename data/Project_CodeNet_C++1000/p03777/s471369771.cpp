#include <iostream>
#include <string>

using namespace std;
int main() {
  int g;
  string a, b;

  cin >> a >> b;

  if (a == "H") {
    g = 1;
  }
  if (a == "D") {
    g = -1;
  }

  if (b == "H") {
    g *= 1;
  }
  if (b == "D") {
    g *= -1;
  }

  if (g == 1) {
    cout << "H" << endl;
  } else if(g == -1) {
    cout << "D" << endl;
  }
  return 0;
}
