#include <iostream>
using namespace std;

int main() {
  int m = 1;
  for (int i=0;i<3;++i) {
    int a;
    cin >> a;
    m *= a;
  }
  cout << (m == 5*5*7 ? "YES" : "NO") << endl;
}