#include <iostream>
using namespace std;

int main() {
  int a;
  int c5 = 0;
  int c7 = 0;
  for (int i=0;i<3;++i) {
    cin >> a;
    if (a == 5) c5++;
    if (a == 7) c7++;
  }
  cout << (c5 == 2 && c7 == 1 ? "YES" : "NO") << endl;
}