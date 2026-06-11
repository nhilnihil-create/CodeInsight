#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using int64 = long long;

int main() {
  char a, b;
  cin >> a >> b;
  if ((a == 'H' & b == 'H') || (a == 'D' & b == 'D')) {
    cout << 'H' << endl;
  } else {
    cout << 'D' << endl;
  }
  return 0;
}