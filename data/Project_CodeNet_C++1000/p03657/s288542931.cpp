#include <iostream>
using namespace std;

int main() {
  int a, b; cin >> a >> b;
  if (a % 3 && b % 3 && (a + b) % 3)
    cout << "Impossible" << endl;
  else
    cout << "Possible" << endl;
}