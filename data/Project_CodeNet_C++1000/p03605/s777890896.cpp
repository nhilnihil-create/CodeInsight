#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
  int N;
  cin >> N;

  div_t d = div(N, 10);
  bool result = ((d.quot == 9) || (d.rem == 9));
  cout << (result ? "Yes" : "No") << endl;
  return 0;
}
