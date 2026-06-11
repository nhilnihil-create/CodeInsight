#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  if(a[0] == a[1] && a[1] == a[2]) cout << 1 << "\n";
  else if(a[0] == a[1] || a[1] == a[2]) cout << 2 << "\n";
  else cout << 3 << "\n";
}
